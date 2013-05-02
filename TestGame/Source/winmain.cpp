#include "TestGame_pch.h"

#include "Application\Engine.h"
#include "Deferred\DeferredRenderer.h"
#include "Havok\Havok.h"
#include "Messenger.h"
#include "Scene.h"
#include "Game\TestGame.h"
#include "Game\DemoStateFactory.h"

using namespace Anubis;

Anubis::Engine* Anubis::g_pEngine = NULL;

////////////////////////////////////
//Entry point for the application
////////////////////////////////////
int WINAPI wWinMain(	HINSTANCE hInstance, 
						HINSTANCE hPrevInstance,
						LPWSTR lpCmdLine,
						int	   nShowCmd)
{
	//set semo debuggin flags
//	int debugFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	//debugFlag	|=	_CRTDBG_LEAK_CHECK_DF;
	//debugFlag	|=	_CRTDBG_CHECK_ALWAYS_DF;
	//debugFlag	|=	_CRTDBG_DELAY_FREE_MEM_DF;

	//_CrtSetDbgFlag(debugFlag);
	AINT32 g_iExit = 0;

	Anubis::g_pEngine = new Engine(); //Allocate memory for the engine

	/* ==== Initialize window === */
	g_pEngine->InitializeWindow(hInstance, nShowCmd, 1280, 720, true);

	/* =========================
		Initialize Game Logic
	   ========================= */
	TestGame g_Game;

	//Manage states factory and set initial state
	g_Game.SetStateFactory(new DemoStateFactory());
	g_Game.SetNextState(GS_GAMETEST);

	/* === Initialize Game === */
	g_pEngine->InitializeGame(&g_Game);

	/* ==============================
		Initialize Engine Components
	   ============================== */

	//Allocate memory for engine subsystems!
	Renderer*	g_pRenderer = new DeferredRenderer();
	IPhysics*	g_pPhysics = CreateHavokPhysics();
	Messenger*	g_pMessenger = new Messenger();

	/* === Initialize main engine components === */
	g_pEngine->InitializeComponents(g_pRenderer, g_pPhysics, g_pMessenger);

	// **************************** //
	// ===						=== //
	// ===		Game Loop		=== //
	// ===						=== //
	// **************************** //
	g_iExit = g_pEngine->Run();

	//Deallocate all the memory and shut down application
	//NOTE!: Engine is responsible for destroying all subsystems in the correct order!!!
	delete g_pEngine;

	return g_iExit;
}