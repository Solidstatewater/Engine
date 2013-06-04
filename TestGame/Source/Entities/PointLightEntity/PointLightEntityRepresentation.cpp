#include "TestGame_pch.h"
#include "PointLightEntityRepresentation.h"

#include "../../Renderer/Meshes/BoxMesh.h"
#include "Lights\PointLight.h"

PointLightEntityRepresentation::PointLightEntityRepresentation(EntityRepresentationId id, const Vec color, const Vec pos, const AREAL32 r32Range)
							: DynamicRepresentation(id, float3(0.0f, 0.0f, 0.0f))
{
	PointLight* pLight = new PointLight(color, pos, r32Range);
	shared_ptr<PointLight> pPointLightPtr = make_shared<PointLight>(*pLight);
	m_lights.push_back(pPointLightPtr);
}