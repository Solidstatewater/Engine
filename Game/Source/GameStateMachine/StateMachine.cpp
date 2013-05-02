#include "Game_pch.h"
#include "StateMachine.h"

using namespace Anubis;

//constructor
StateMachine::StateMachine()
{
	m_pCurrentState = NULL;
}

AVOID StateMachine::Release(Game * pGame)
{
	ReleaseCurrentState(pGame);
}

//Set a new state
ABOOL StateMachine::SetState(Game * pGame, State * pState, AINT32 i32StateId)
{
	//some error occured deleting current state
	if (!ReleaseCurrentState(pGame))
		return false;

	//assign new state as current
	m_pCurrentState = pState;

	//nothing else is left to do for null states
	if (!pState)
		return true;

	//assign state id
	m_pCurrentState->m_i32Id = i32StateId;

	//initialize new game state
	m_pCurrentState->VInitialize(pGame);

	return true;
}

//Destroy current state
ABOOL StateMachine::ReleaseCurrentState(Game * pGame)
{
	//current state is null
	if (!m_pCurrentState)
		return true;

	//destroy current state and release memory
	m_pCurrentState->VRelease(pGame);
	delete m_pCurrentState;

	//set current state to NULL
	m_pCurrentState = NULL;

	return true;
}

//Update
AVOID StateMachine::VUpdate(Game * pGame, AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	if (m_pCurrentState)
		m_pCurrentState->VUpdate(pGame, r64Time, r64ElapsedTime);
}

//Render
AVOID StateMachine::VRender(Game * pGame, Renderer * pRenderer, AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	if (m_pCurrentState)
		m_pCurrentState->VRender(pGame, pRenderer, r64Time, r64ElapsedTime);
}