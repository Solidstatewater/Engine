#include "Scene_pch.h"
#include "Scene.h"

#include "Allocator.h"

using namespace Anubis;

Scene::Scene()
{
	//initialize root node
	//RootRepresentation * pRepr = allocator._new<RootRepresentation>();
	//m_pRoot = make_shared<RootRepresentation>(*pRepr);
	Allocator allocator;
	APVOID pMemory = allocator.allocateAligned(sizeof(RootRepresentation), 16);
	m_pRoot = new (pMemory) RootRepresentation();
}

Scene::~Scene()
{
	delete m_pRoot;
}

/***	====	Initialization	====	***/
ABOOL Scene::VInitialize()
{
	return true;
}

/***	====	Updating	====	***/
AVOID Scene::VUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
}

/***	====	Rendering	====	***/
AVOID Scene::VRender(Renderer * pRenderer, AREAL64 r64CurrentTime)
{
	m_pRoot->VRender(this, pRenderer, r64CurrentTime);
}

/***	====	Representations management	====	***/
EntityRepresentation* Scene::GetRepresentation(EntityRepresentationId id)
{
	return m_pRoot->VFindChild(id);
}

ABOOL Scene::RemoveRepresentation(EntityRepresentationId id)
{
	return false;
}

AVOID Scene::AddRepresentation(EntityRepresentation* pRepresentation,
			RenderPass pass, EntityRepresentationId parentId)
{
	m_pRoot->VAddChild(pRepresentation, pass, parentId);
}

//update current world transform
AVOID Scene::PushTransform(const Mat4x4 & mat)
{
	m_transforms.PushTransform(mat);
}

//remove last transform
AVOID Scene::PullTransform()
{
	m_transforms.Pop();
}