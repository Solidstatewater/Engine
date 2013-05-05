#include "Scene_pch.h"
#include "Representation.h"
#include "../Scene.h"

using namespace Anubis;

EntityRepresentation::~EntityRepresentation()
{
	for (EntityRepresentation * pRepr : m_children)
	{
		delete pRepr;
	}
}

//Add and remove children
AVOID EntityRepresentation::VAddChild(EntityRepresentation* pRepr)
{
	//add child to the list
	m_children.push_back(pRepr);
}

AVOID EntityRepresentation::VRemoveChild(EntityRepresentationId id)
{
}

EntityRepresentation* EntityRepresentation::VFindChild(EntityRepresentationId id)
{
	//compare IDs and return 
	//representation if equal
	if (m_id == id)	return this;

	//check out children
	for (EntityRepresentation* pRepr : m_children)
	{
		EntityRepresentation* pResult = pRepr->VFindChild(id);

		if (pResult) return pResult;
	}

	//not found
	return NULL;
}

AVOID EntityRepresentation::VAddMesh(MeshPtr pMesh)
{
	m_meshes.push_back(pMesh);
}

AVOID EntityRepresentation::VAddLight(LightPtr pLight)
{
	m_lights.push_back(pLight);
}

AVOID EntityRepresentation::SetCurrentTransform(Mat4x4 & mat, AREAL64 r64CurrentTime)
{
	m_currentWorldMatrix = mat;
	m_r64LastUpdate = r64CurrentTime;
}

//put all low-level mesh data to the renderer
AVOID EntityRepresentation::VRender(Scene * pScene, Renderer * pRenderer, AREAL64 r64CurrentTime)
{
	//push parameteres to the scene
	VPushParameters(pScene, r64CurrentTime);

	//send rendering data to the renderer
	VSendRenderingData(pScene, pRenderer);

	//render all children
	for (EntityRepresentation* pRepr : m_children)
		pRepr->VRender(pScene, pRenderer, r64CurrentTime);

	//undo all changes made to the scene
	VPullParameters(pScene);
}

//pre-rendering modifications
AVOID EntityRepresentation::VPushParameters(Scene *pScene, AREAL64 r64CurrentTime)
{
	pScene->PushTransform(m_currentWorldMatrix);
}

//push data to the renderer
AVOID EntityRepresentation::VSendRenderingData(Scene * pScene, Renderer * pRenderer)
{
	//send all meshes to the renderer
	for (MeshPtr pMesh : m_meshes)
	{
		pMesh->SetWorldTransform(pScene->GetTransform());
		pRenderer->VPushMesh(&*pMesh);
	}

	//send all lights to the renderer
	for (LightPtr pLight : m_lights)
	{
		pRenderer->VPushLight(&*pLight);
	}
}

//undo any changes made to the scene
AVOID EntityRepresentation::VPullParameters(Scene * pScene)
{
	pScene->PullTransform();
}