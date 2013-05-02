#include "Game_pch.h"
#include "EntityManager.h"

using namespace Anubis;

//Return entity by its id
EntityPtr EntityManager::VGetEntity(const EntityId id)
{
	//iterate the list and extract our entity
	for (auto ent = m_entities.begin(); ent != m_entities.end(); ent++)
		//the entity with such id found
			if ((*ent)->GetId() == id)
				return (*ent);

	ASSERT(0 && "No entity with such Id!");
	return nullptr;
}

//Add entity to the manager
AVOID EntityManager::VAddEntity(EntityPtr pEntity)
{
	//just insert it to the list
	m_entities.push_back(pEntity);
}

//Remove entity from the manager
ABOOL EntityManager::VRemoveEntity(const EntityId id)
{
	//iterate the list and extract our entity
	auto ent = m_entities.begin();
	for (; ent != m_entities.end(); ent++)
		//the entity with such id found
			if ((*ent)->GetId() == id)
				break;

	if (ent != m_entities.end())
	{
		m_entities.erase(ent);
		return true;
	}

	return false;
}

//Update entity transform matrix
AVOID EntityManager::VUpdateEntity(const EntityId id, Mat4x4 const & transform)
{
	//iterate the list and extract our entity
	for (auto ent = m_entities.begin(); ent != m_entities.end(); ent++)
		//the entity with such id found
			if ((*ent)->GetId() == id)
			{
				(*ent)->SetCurrentTransform(transform);
				return;
			}

	ASSERT(0 && "No entity with such Id!");
}