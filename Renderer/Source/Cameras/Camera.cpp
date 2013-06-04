#include "Renderer_pch.h"
#include "Camera.h"

using namespace Anubis;

Camera::Camera(	const Frustum & frustum,
				Vec & position, Vec & dir, Vec & up,
				AREAL yaw, AREAL pitch, AREAL roll,
				Viewport * pViewport/* = NULL */)
				:	
					m_frustum(frustum), m_bActive(true), m_bDebug(false),
					m_pos(position), m_up(up),
					m_yaw(yaw), m_pitch(pitch), m_roll(roll)
{
	m_dir = Normalize(dir);

	//initalize matrices
	UpdateTransforms();

	//assign viewport
	m_pViewport = pViewport;
}
Camera::~Camera()
{
	SAFE_DELETE(m_pViewport);
}

AVOID Camera::UpdateTransforms()
{
	Mat4x4 rot;
	rot = rot.CreateRollPitchYaw(m_roll, m_pitch, m_yaw);

	//calculate point camera is focusing
	m_lookAt = m_pos + m_dir * rot;

	//calculate view and projection matrices
	m_view			= CreateViewMatrixLH(m_pos, m_dir, m_up);
	m_projection	= CreatePerspectiveProjectionLH(	m_frustum.GetFOV(), m_frustum.GetAspectRatio(),
														m_frustum.GetNearZ(), m_frustum.GetFarZ() );
}

AVOID Camera::VUpdate(AUINT32 const elapsedMs)
{
	UpdateTransforms();
}

Mat4x4 Camera::GetOrthoProjection() const
{
	return CreateOrthoProjectionLH(1280, 720, m_frustum.GetNearZ(), m_frustum.GetFarZ());
}

Vec Camera::GetLookAt() const
{
	Mat4x4 rot;
	rot = rot.CreateRollPitchYaw(m_roll, m_pitch, m_yaw);

	Vec lookAt;
	lookAt = m_pos + m_dir * rot;

	return lookAt;
}