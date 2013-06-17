#include "TestGame_pch.h"

#include "PlaneEntity.h"


#include "../../Renderer/Meshes/PlaneMesh.h"
#include "Data\JSONLoader.h"
#include "Application\Engine.h"
#include "../../Math/Source/Mat4x4.h"

#include <Allocator.h>

using namespace Anubis;

////////////////////////////////////////////////////////////
//PlaneEntitiy Resource
////////////////////////////////////////////////////////////

AVOID PlaneEntityResource::VLoad(const ASTRING & filename)
{
	EntityResource::VLoad(filename);

	//load size
	m_r32Width = JSONLoader::GetAREAL32("width");
	m_r32Height = JSONLoader::GetAREAL32("height");
}

EntityResource & PlaneEntityResource::VCopy()
{
	return static_cast<EntityResource &>(*this);
}

//create entity
EntityPtr PlaneEntityResource::VCreateEntity(Game * pGame)
{
	return pGame->VAddEntity(make_shared<Entity>(PlaneEntity(pGame->GetNewEntityId())));
}

EntityRepresentation* PlaneEntityResource::VCreateRepresentation(Scene * pScene, EntityPtr pEntity)
{
	Allocator allocator;
	APVOID pMemory = allocator.allocateAligned(sizeof(PlaneEntityRepresentation), 16);
	PlaneEntityRepresentation * pPlanePointer = new (pMemory) PlaneEntityRepresentation(pEntity->GetId(), L"diffuse_white.jpg", L"normal_white.jpg",
		L"specular_white.jpg", L"height_white.jpg", float2(m_r32Width, m_r32Height));
	pPlanePointer->SetSize(m_r32Width, m_r32Height, 1.0f);
	Mat4x4 trans;
	trans.CreateTranslation(m_pos);
	pPlanePointer->SetCurrentTransform(trans, g_pEngine->GameTimeInSeconds());
	pScene->AddRepresentation(pPlanePointer);

	return pPlanePointer;
}

AVOID PlaneEntityResource::VCreatePhysicalBody(IPhysics * pPhysics)
{
}

////////////////////////////////////////////////////////////
//PlaneEntity Representation
////////////////////////////////////////////////////////////
PlaneEntityRepresentation::PlaneEntityRepresentation(EntityRepresentationId id, AWSTRING diffuseMaterialFile, AWSTRING normalMaterialFile,
							AWSTRING specularMaterialFile, AWSTRING heightMaterialFile, const float2 & f2Size)
							: EntityRepresentation(id)
{
	PlaneMesh* pPlaneMesh = new PlaneMesh("", f2Size.x, f2Size.y);
	pPlaneMesh->VSetMaterial(diffuseMaterialFile, normalMaterialFile, specularMaterialFile, heightMaterialFile);
	shared_ptr<PlaneMesh> pPlaneMeshPtr = make_shared<PlaneMesh>(*pPlaneMesh);
	m_meshes.push_back(pPlaneMeshPtr);
}