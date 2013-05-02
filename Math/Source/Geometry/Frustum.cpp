#include "Math_pch.h"
#include "Frustum.h"

using namespace Anubis;

Frustum::Frustum()
{
	m_fov = (AREAL)Pi/4.0f;										//default field of view is 90 degrees
	m_aspect = (AREAL)SCREEN_WIDTH/(AREAL)SCREEN_HEIGHT;//default aspect ratio 
	m_near = 0.1f;										//default near clip plane is 1m away from the camera
	m_far = 1000.0f;									//default near clip plane is 100m away from the camera
}

Frustum::~Frustum()
{
}


ABOOL Frustum::Inside(const Vec & point) const
{
	//point is inside the frustum only if it is inside each of the plain
	for (AINT8 i=0; i<NumPlanes; ++i)
	{
		if (!m_planes[i].Inside(point))
			return false;
	}

	return true;
}

ABOOL Frustum::Inside(const Vec & point, const AREAL radius) const
{
	//point is inside the frustum only if it is inside each of the plain
	for(int i = 0; i < NumPlanes; ++i) 
	{	
		if (!m_planes[i].Inside(point, radius))
			return false;
	}	
	
	//we are fully in view
	return true;
} 

AVOID Frustum::Init(const AREAL fov, const AREAL aspect, const AREAL nearClip, const AREAL farClip)
{
	//Copy values
	m_fov = fov;
	m_aspect = aspect;
	m_near = nearClip;
	m_far = farClip;

	AREAL64 tanFov		= Tg(m_fov);
	Vec nearRightOffset	= (m_near * tanFov) * m_aspect * g_right4;
	Vec farRightOffset	= (m_far  * tanFov) * m_aspect * g_right4;
	Vec nearUpOffset	= (m_near * tanFov) * g_up4;
	Vec farUpOffset		= (m_far  * tanFov) * g_up4;

	// points start in the upper left and go around clockwise
	m_nearClip[0] = (m_near * g_forward4) - nearRightOffset + nearUpOffset;
	m_nearClip[1] = (m_near * g_forward4) + nearRightOffset + nearUpOffset;
	m_nearClip[2] = (m_near * g_forward4) + nearRightOffset - nearUpOffset;
	m_nearClip[3] = (m_near * g_forward4) - nearRightOffset - nearUpOffset;

	m_farClip[0] = (m_far * g_forward4) - farRightOffset + farUpOffset;
	m_farClip[1] = (m_far * g_forward4) + farRightOffset + farUpOffset;
	m_farClip[2] = (m_far * g_forward4) + farRightOffset - farUpOffset;
	m_farClip[3] = (m_far * g_forward4) - farRightOffset - farUpOffset;

	// now we have all eight points, now construct 6 planes.
	// the normals point away from you if you use counter clockwise verts.

	Vec origin = Vector(0.0f, 0.0f, 0.0f, 1.0f);
	m_planes[Near].InitFromPoints(m_nearClip[2], m_nearClip[1], m_nearClip[0]);
	m_planes[Far].InitFromPoints(m_farClip[0], m_farClip[1], m_farClip[2]);
	m_planes[Right].InitFromPoints(m_farClip[2], m_farClip[1], origin);
	m_planes[Top].InitFromPoints(m_farClip[1], m_farClip[0], origin);
	m_planes[Left].InitFromPoints(m_farClip[0], m_farClip[3], origin);
	m_planes[Bottom].InitFromPoints(m_farClip[3], m_farClip[2], origin);
} 

//
// Frustum::Render					
//
void Frustum::Render()
{
	/*COLORED_VERTEX verts[24];
	for (int i=0; i<8; ++i)
	{
		verts[i].color = g_White;
	}

	for (int i=0; i<8; ++i)
	{
		verts[i+8].color = g_Red;
	}

	for (int i=0; i<8; ++i)
	{
		verts[i+16].color = g_Blue;
	}


	// Draw the near clip plane
	verts[0].position = m_NearClip[0];	verts[1].position = m_NearClip[1];
	verts[2].position = m_NearClip[1];	verts[3].position = m_NearClip[2];
	verts[4].position = m_NearClip[2];	verts[5].position = m_NearClip[3];
	verts[6].position = m_NearClip[3];	verts[7].position = m_NearClip[0];

	// Draw the far clip plane
	verts[8].position = m_FarClip[0];	verts[9].position = m_FarClip[1];
	verts[10].position = m_FarClip[1];	verts[11].position = m_FarClip[2];
	verts[12].position = m_FarClip[2];	verts[13].position = m_FarClip[3];
	verts[14].position = m_FarClip[3];	verts[15].position = m_FarClip[0];

	// Draw the edges between the near and far clip plane
	verts[16].position = m_NearClip[0];	verts[17].position = m_FarClip[0];
	verts[18].position = m_NearClip[1];	verts[19].position = m_FarClip[1];
	verts[20].position = m_NearClip[2];	verts[21].position = m_FarClip[2];
	verts[22].position = m_NearClip[3];	verts[23].position = m_FarClip[3];

	DWORD oldLightMode;
	DXUTGetD3D9Device()->GetRenderState( D3DRS_LIGHTING, &oldLightMode );
	DXUTGetD3D9Device()->SetRenderState( D3DRS_LIGHTING, FALSE );

    DXUTGetD3D9Device()->SetFVF( COLORED_VERTEX::FVF );
	DXUTGetD3D9Device()->DrawPrimitiveUP( D3DPT_LINELIST, 12, verts, sizeof(COLORED_VERTEX) );

	DXUTGetD3D9Device()->SetRenderState( D3DRS_LIGHTING, oldLightMode ); */
}