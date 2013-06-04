#include "Scene_pch.h"
#include "DynamicRepresentation.h"

#include "../../../Math/Source/Interpolation.h"

using namespace Anubis;

AVOID DynamicRepresentation::SetBothTransforms(Mat4x4 & mat, AREAL64 r64CurrentTime)
{
	m_prevWorldMatrix = mat;
	m_currentWorldMatrix = mat;
	m_r64LastUpdate = r64CurrentTime;
}

//pre-rendering modifications
AVOID DynamicRepresentation::VPushParameters(Scene *pScene, AREAL64 r64CurrentTime)
{
	Mat4x4 transform;

	//new update cycle - current transform has changed
	if (m_prevWorldMatrix != m_currentWorldMatrix)
	{
		transform = LERP(m_prevWorldMatrix, m_currentWorldMatrix, min((r64CurrentTime - m_r64LastUpdate) / pScene->GetFixedTimeStep(), 1));
	}
	else
	{
		//we are not updating anything, so use current transform
		transform = m_currentWorldMatrix;
	}

	pScene->PushTransform(transform);
}