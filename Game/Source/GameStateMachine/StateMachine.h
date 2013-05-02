#pragma once
//========================================================================
// StateMachine.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "State.h"

namespace Anubis
{
	/** ======================
			States Manager
	    ====================== **/
	class StateMachine
	{
	public:

		//Constructor
		StateMachine();
		
		AVOID Release(Game * pGame);

		//====================
		// State management
		//====================
		ABOOL SetState(Game * pGame, State * pState, AINT32 i32StateId); //set current state
		ABOOL ReleaseCurrentState(Game * pGame); //remove current state

		//====================
		// Running
		//====================
		AVOID VUpdate(Game * pGame, AREAL64 r64Time, AREAL64 r64ElapsedTime);
		AVOID VRender(Game * pGame, Renderer * pRenderer, AREAL64 r64Time, AREAL64 r64ElapsedTime);

	private:

		//Current State
		State *	m_pCurrentState;
	};
}; //Anubis