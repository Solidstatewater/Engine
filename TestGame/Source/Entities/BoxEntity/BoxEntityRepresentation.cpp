#include "TestGame_pch.h"
#include "BoxEntityRepresentation.h"

#include "../../Renderer/Meshes/BoxMesh.h"

BoxEntityRepresentation::BoxEntityRepresentation(EntityRepresentationId id, AWSTRING diffuseMaterialFile, AWSTRING normalMaterialFile,
							AWSTRING specularMaterialFile, AWSTRING heightMaterialFile)
							: DynamicRepresentation(id)
{
	BoxMesh* pBoxMesh = new BoxMesh("");
	pBoxMesh->VSetMaterial(diffuseMaterialFile, normalMaterialFile, specularMaterialFile, heightMaterialFile);
	shared_ptr<BoxMesh> pBoxMeshPtr = make_shared<BoxMesh>(*pBoxMesh);
	m_meshes.push_back(pBoxMeshPtr);
}