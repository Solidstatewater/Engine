#pragma once
//========================================================================
// State.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Renderer.h"
#include "Scene.h"

namespace Anubis
{

	//Unique identifier for each game state
	typedef AUINT32 StateId;

	/** =======================
		 Represents Game State
	    ======================= **/
	class Game;
	class State
	{
		friend class StateMachine;

	protected:

		//Time the state is running in ms
		AINT64	m_i64Time;

		//Unique id
		AINT32	m_i32Id;

		//Scene
		Scene *	m_pScene;

	public:

		//Constructor and Destructor
		State() 
		{
			m_pScene = new Scene();
		}

		AVIRTUAL ~State() {}

		//=========================================
						//Methods//
		//=========================================

		AVIRTUAL AVOID VInitialize( Game * pGame, AUINTPTR uptrData = 0 ) = 0;					//Initialize game state

		AVIRTUAL AVOID VRelease( Game * pGame ) = 0;											//Destroy the state

		AVIRTUAL AVOID VUpdate( Game * pGame, AREAL64 r64Time, AREAL64 r64ElapsedTime ) = 0;	//Update the state

		AVIRTUAL AVOID VRender( Game * pGame, Renderer * pRenderer, AREAL64 r64Time, AREAL64 r64ElapsedTime ) = 0;	//Render State
	};

}; //Anubis