#pragma once
//========================================================================
// CubeEntityResource.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Entities\EntityResource.h"

struct ALIGN16 BoxEntityResource : public EntityResource
{
	/***	Box size	***/
	AREAL	m_r32X;
	AREAL	m_r32Y;
	AREAL	m_r32Z;

	BoxEntityResource() : EntityResource(),
		m_r32X(5.0f), m_r32Y(5.0f), m_r32Z(5.0f) 
	{
	}

	~BoxEntityResource() {}

	//create entity
	EntityPtr	VCreateEntity(Game * pGame);

	//create its representation
	EntityRepresentation* VCreateRepresentation(Scene * pScene, EntityPtr pEntity);

	//create its physics model
	AVOID VCreatePhysicalBody(IPhysics * pPhysics);

	/// ***	Copy resource data *** ///
	EntityResource & VCopy();
};