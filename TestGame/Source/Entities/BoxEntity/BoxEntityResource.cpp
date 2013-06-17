#include "TestGame_pch.h"
#include "BoxEntityResource.h"

#include "BoxEntity.h"
#include "BoxEntityRepresentation.h"

#include "Data\JSONLoader.h"

#include "Application\Engine.h"

#include "../../Math/Source/Mat4x4.h"

#include <Allocator.h>

using namespace Anubis;

AVOID BoxEntityResource::VLoad(const ASTRING & filename)
{
	EntityResource::VLoad(filename);

	//load size
	m_r32X = JSONLoader::GetAREAL32("size_x");
	m_r32Y = JSONLoader::GetAREAL32("size_y");
	m_r32Z = JSONLoader::GetAREAL32("size_z");
}

EntityResource & BoxEntityResource::VCopy()
{
	return static_cast<EntityResource &>(*this);
}

//create entity
EntityPtr BoxEntityResource::VCreateEntity(Game * pGame)
{
	return pGame->VAddEntity(make_shared<Entity>(BoxEntity(pGame->GetNewEntityId())));
}

EntityRepresentation* BoxEntityResource::VCreateRepresentation(Scene * pScene, EntityPtr pEntity)
{
	Allocator allocator;
	APVOID pMemory = allocator.allocateAligned(sizeof(BoxEntityRepresentation), 16);
	BoxEntityRepresentation * pBoxPointer = new (pMemory) BoxEntityRepresentation(pEntity->GetId(), L"diffuse.jpg", L"normal.jpg", L"specular.jpg", L"height.jpg", float3(m_r32X, m_r32Y, m_r32Z));
	pBoxPointer->SetSize(m_r32X, m_r32Y, m_r32Z);
	Mat4x4 trans;
	trans.CreateTranslation(m_pos);
	pBoxPointer->SetBothTransforms(trans, g_pEngine->GameTimeInSeconds());
	pScene->AddRepresentation(pBoxPointer);

	return pBoxPointer;
}

AVOID BoxEntityResource::VCreatePhysicalBody(IPhysics * pPhysics)
{
}