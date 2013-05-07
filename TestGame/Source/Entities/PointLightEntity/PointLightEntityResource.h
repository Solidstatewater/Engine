#pragma once
//========================================================================
// PointLightEntityResource.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Entities\EntityResource.h"
#include "../../Math/Source/Vectors.h"

struct ALIGN16 PointLightEntityResource : public EntityResource
{
	/*** Light properties ***/
	Vec		m_color;
	Vec		m_pos;
	AREAL32 m_r32Range;

	PointLightEntityResource() : EntityResource()
	{
		m_color = Vector(1.0f, 1.0f, 1.0f, 1.0f);
		m_pos = Vector(-2.0f, 2.0f, -2.0f, 1.0f);
		m_r32Range = 10.0f;
	}

	~PointLightEntityResource() {}

	//create entity
	EntityPtr	VCreateEntity(Game * pGame);

	//create its representation
	EntityRepresentation* VCreateRepresentation(Scene * pScene, EntityPtr pEntity);

	//create its physics model
	AVOID VCreatePhysicalBody(IPhysics * pPhysics);

	/// ***	Copy resource data *** ///
	EntityResource & VCopy();
};