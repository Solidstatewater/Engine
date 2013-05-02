#pragma once
//========================================================================
// EntityManager.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Entity.h"
#include "EntityResource.h"

namespace Anubis
{
	//======================================//
	//		Entity Manager Interface        //
	//										//
	//	Manages, sort and updates all game	//
	//	entities.							//
	//======================================//
	class IEntityManager
	{
	public:
		//Return entity by its id
		AVIRTUAL EntityPtr	VGetEntity(const EntityId id) = 0;

		//Add entity to the manager
		AVIRTUAL AVOID		VAddEntity(EntityPtr pEntity) = 0;

		//Remove entity from the manager
		AVIRTUAL ABOOL		VRemoveEntity(const EntityId id) = 0;

		//Update entity transform matrix
		AVIRTUAL AVOID		VUpdateEntity(const EntityId id, Mat4x4 const & transform) = 0;
	};

	////////////////////////////////////////
	//Implementation of Entity Manager
	////////////////////////////////////////
	class EntityManager : public IEntityManager
	{
	private:

		//List of entities 
		typedef vector<EntityPtr>	Entities;
		Entities	m_entities;

		AUINT32		m_count; //number of entities in the list

	public:

		///////////////////////////////////////
		/*** IEntityManager Implementation ***/
		//									 //
		///////////////////////////////////////

		//Return entity by its id
		AVIRTUAL EntityPtr	VGetEntity(const EntityId id);

		//Add entity to the manager
		AVIRTUAL AVOID		VAddEntity(EntityPtr pEntity);

		//Remove entity from the manager
		AVIRTUAL ABOOL		VRemoveEntity(const EntityId id);

		//Update entity transform matrix
		AVIRTUAL AVOID		VUpdateEntity(const EntityId id, Mat4x4 const & transform);
	};

}; //Anubis