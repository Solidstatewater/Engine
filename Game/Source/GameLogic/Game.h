#pragma once
//========================================================================
// Game.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../Entities/EntityManager.h"
#include "../GameStateMachine/StateFactory.h"
#include "../GameStateMachine/StateMachine.h"
#include "Views.h"

#include "../../../Math/Source/Mat4x4.h"

namespace Anubis
{
	class EntityManager;
	class Game
	{
	protected:
		/** -------------------
			Entities
		----------------------- **/
		EntityId		m_lastEntityId; //id of last added actor
		EntityManager*	m_pEntityManager; //entity manager

		/** -------------------
			States
		----------------------- **/
		StateFactory*	m_pStateFactory;
		StateMachine*	m_pStateMachine;

		//keep data about the next game state
		struct NextGameState
		{
			AINT32		m_i32Id;	//next state id
			AUINTPTR	m_uptrData; //next state data
			ABOOL		m_bSetState;//true if state change is necessary
		};
		NextGameState	m_ngsState;

		/** -------------------
			Views
		----------------------- **/
		Views		m_views;

	public:
		//constructor and destructor
		Game();
		AVIRTUAL ~Game();

		//============================
		// Initializing
		//============================

		//main initialization
		AVIRTUAL ABOOL VInitialize();

		//game states
		AVOID SetStateFactory(StateFactory * pStateFactory);
		AVOID SetNextState(AINT32 i32StateId, AUINTPTR uptrData = 0);
		
		/*==
		//App stuff
		==*/
		AVIRTUAL LRESULT	VMsgProc(AppMsg & msg);

		/*==
		//Updating methods
		==*/
		AVIRTUAL AVOID		VUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime);

		/*==
		//Rendering methods
		==*/
		AVIRTUAL AVOID		VRender(Renderer * pRenderer, AREAL64 r64Time, AREAL64 r64ElapsedTime);
		AVIRTUAL AVOID		VRenderDebug();

///////////////////////////////////////////////////////////////////////////////////////////

		/*==
		//Entities management
		==*/
		AVIRTUAL EntityPtr	VAddEntity(EntityPtr pEntity);
		AVIRTUAL EntityPtr	VGetEntity(const EntityId id);
		AVIRTUAL ABOOL		VRemoveEntity(const EntityId id);

		//Update entity transform matrix
		AVIRTUAL AVOID		VUpdateEntity(const EntityId id, Mat4x4 const & transform);
		AINLINE  EntityId	GetNewEntityId() { return ++m_lastEntityId; }

		/*==
		//States management
		==*/
		ABOOL SetState(AINT32 i32StateId);

		/*==
		//Views management
		==*/
		AVIRTUAL ViewPtr	VAddGameView(shared_ptr<IView> pView);
		AVIRTUAL AVOID		VRemoveGameView(shared_ptr<IView> pView);
		const	 Views *	 GetViews() const { return &m_views; }
	};
}; //Anubis