#pragma once
//========================================================================
// EntityResource.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Math/Source/Vectors.h"

#include "../GameLogic/Game.h"
#include "PhysicsInterface.h"
#include "Representations\Representation.h"

namespace Anubis
{
	class Game;
	struct ALIGN16 EntityResource
	{
		//position
		Vec	m_pos;

		ASTRING	m_name; //mainly for debugging purposes

		//Mat4x4	m_mat;

		//identifier
		EntityId	m_id;

		EntityResource(EntityId id = 0) : m_id(id)	{}
		AVIRTUAL AVOID VLoad(const ASTRING & filename);
		AVIRTUAL ~EntityResource()	{}

		//	 =====================	 //
		//		Factory Pattern		 //
		//	 =====================	 //

		//create entity
		AVIRTUAL EntityPtr	VCreateEntity(Game * pGame) = 0;

		//create its representation
		AVIRTUAL EntityRepresentation* VCreateRepresentation(Scene * pScene, EntityPtr pEntity) = 0;

		//create its physics model
		AVIRTUAL AVOID VCreatePhysicalBody(IPhysics * pPhysics) = 0;

		/// ***	Copy resource data *** ///
		AVIRTUAL EntityResource & VCopy() = 0;
	};
};