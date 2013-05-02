#include "TestGame_pch.h"
#include "BoxEntityResource.h"

#include "BoxEntity.h"
#include "BoxEntityRepresentation.h"

#include <Allocator.h>

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
	BoxEntityRepresentation * pBoxPointer = new (pMemory) BoxEntityRepresentation(pEntity->GetId(), L"diffuse.jpg", L"normal.jpg", L"specular.jpg", L"height.jpg");
	pScene->AddRepresentation(pBoxPointer);

	return pBoxPointer;
}

AVOID BoxEntityResource::VCreatePhysicalBody(IPhysics * pPhysics)
{
}