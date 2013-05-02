#include "Game_pch.h"
#include "Game.h"

using namespace Anubis;

Game::Game() : m_lastEntityId(0)
{
	m_pStateMachine = NULL;
	m_pEntityManager = NULL;
}

Game::~Game()
{
	m_pStateMachine->Release(this);
	m_pStateMachine = NULL;
}

ABOOL Game::VInitialize()
{
	//create state machine
	m_pStateMachine = new StateMachine();

	//create entity manager
	m_pEntityManager = new EntityManager();

	return true;
}

LRESULT	Game::VMsgProc(AppMsg & msg)
{
	return 1;
}

AVOID Game::VUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	//change game state if needed
	if (m_ngsState.m_bSetState)
	{
		m_ngsState.m_bSetState = false;
		SetState(m_ngsState.m_i32Id);
	}

	//update a game state
	m_pStateMachine->VUpdate(this, r64Time, r64ElapsedTime);

	const AUINT32 deltaMilliseconds = AUINT32(r64ElapsedTime * 1000.0f);
	for (Views::iterator iter = m_views.begin(); iter != m_views.end(); iter++)
		(*iter)->VUpdate(deltaMilliseconds);
}

/********************************
** Entities management
*********************************/
EntityPtr Game::VAddEntity(EntityPtr pEntity)
{
	m_pEntityManager->VAddEntity(pEntity);
	return pEntity;
}

EntityPtr Game::VGetEntity(const EntityId id)
{
	return m_pEntityManager->VGetEntity(id);
}

ABOOL Game::VRemoveEntity(const EntityId id)
{
	return m_pEntityManager->VRemoveEntity(id);
}

AVOID Game::VUpdateEntity(const EntityId id, Mat4x4 const & transform)
{
	m_pEntityManager->VUpdateEntity(id, transform);
}

/********************************
** States management
*********************************/
AVOID Game::SetStateFactory(StateFactory * pStateFactory)
{
	m_pStateFactory = pStateFactory; 
}

AVOID Game::SetNextState(AINT32 i32StateId, AUINTPTR uptrData)
{
	m_ngsState.m_i32Id = i32StateId;
	m_ngsState.m_uptrData = uptrData;
	m_ngsState.m_bSetState = true;
}

ABOOL Game::SetState(AINT32 i32StateId)
{
	//create state
	State * pState = m_pStateFactory->VCreateState(i32StateId);

	//bind state
	return m_pStateMachine->SetState(this, pState, i32StateId);
}

/********************************
** Views management
*********************************/
ViewPtr Game::VAddGameView(ViewPtr pView)
{
	m_views.push_back(pView);
	return pView;
}

AVOID Game::VRemoveGameView(ViewPtr pView)
{
}

/**********************************
** Rendering methods
**********************************/
AVOID Game::VRenderDebug()
{
}

AVOID Game::VRender(Renderer * pRenderer, AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	//render current game state
	for (Views::iterator iter = m_views.begin(); iter != m_views.end(); iter++)
		(*iter)->VRender(r64Time, r64ElapsedTime);

	//render a game state
	m_pStateMachine->VRender(this, pRenderer, r64Time, r64ElapsedTime);
}