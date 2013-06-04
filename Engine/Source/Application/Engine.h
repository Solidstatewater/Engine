#pragma once

#include "../Time/Timer.h"

#include "../../../Renderer/Source/Deferred/DeferredRenderer.h"
#include "../../../Messenger/Source/Messenger.h"
#include "../../../Renderer/Source/Renderer.h"
#include "../../../Physics/Source/PhysicsInterface.h"
#include "../../../Game/Source/GameLogic/Game.h"

namespace Anubis
{
	class Engine
	{
	public:

		//initialization
		Engine() : m_r64LastUpdate(0), m_r64TimeStep(0.0333), m_bQuitting(false) 
		{
			m_pTimer = new Timer(); //initialize game timer
			m_windowClassName = L"window";
		}

		ABOOL AlreadyRunning(LPCTSTR title);

		//accessors
		//HWND		GetHwnd()		const { return DXUTGetHWND(); }
		HINSTANCE	GetInstance()	const { return m_hInstance; }
		//int			GetExitCode()	const { return DXUTGetExitCode(); }

		//Application specific
		//AVIRTUAL TCHAR *VGetTitle() const = 0;
		//AVIRTUAL TCHAR *VGetDirectory() const = 0;
		//AVIRTUAL HICON VGetIcon() const = 0;

		//Win32 stuff
		ASTATIC LRESULT ACALLBACK WndProc(HWND hwnd, AUINT32 msg, WPARAM wParam, LPARAM lParam);

		ABOOL MsgProc(SystemMessage & message);

		AVOID Update(AREAL64 r64Time, AREAL64 r64ElapsedTime);
		AVOID Render(AREAL64 r64Time, AREAL64 r64ElapsedTime);

		/*============================================
		//Engine Initialization
		=============================================*/
		AVOID InitializeWindowAndGame(HINSTANCE hInstance, AINT32 showWnd, AINT32 width, AINT32 height, ABOOL isWindowed, Game* pGame);
		AVOID InitializeComponents(Renderer* pRenderer, IPhysics* pPhysics, Messenger* pMessenger);

		AVOID InitializeWindow(HINSTANCE hInstance, AINT32 showWnd, AINT32 width, AINT32 height, ABOOL isWindowed);
		AVOID InitializeGame(Game * pGame);

		/*============================================
		//Application main loop
		=============================================*/
		AINT32 Run();

		/*============================================
		//Application Shut Down
		=============================================*/
		AVOID Close();

		/*============================================
		//Access Data
		=============================================*/
		AREAL64 GameTimeInSeconds() const		{ return m_pTimer->GetGameTimeSeconds(); }
		AREAL64 CurrentTimeInSeconds() const	{ return m_pTimer->GetCurrentTimeSeconds(); }

		/*
		ASTATIC LRESULT	ACALLBACK OnMsgProc(HWND hWnd, AUINT32 msg, WPARAM wParam, LPARAM lParam, ABOOL* pbNoFurtherProcessing, APVOID puserContext);
		ASTATIC AVOID	ACALLBACK OnUpdate(AREAL64 fTime, AREAL32 fElapsedTime, APVOID pUserContext);
		ASTATIC AVOID	ACALLBACK OnRender(ID3D11Device* pDevice, ID3D11DeviceContext* pDevCon, AREAL64 fTime, AREAL32 fElapsedTime, APVOID pUserContext);
		//	static HRESULT	CALLBACK OnCreateDevice(ID3D11Device* pDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext);
		ASTATIC AVOID	ACALLBACK OnDestroyDevice(APVOID pUserContext);
		*/

		/*============================================
		//Game Initialization
		=============================================*/
		//AVIRTUAL Game* VCreateGame() = 0;
		//AVIRTUAL AVOID RegisterGameSpecificEvents() = 0;

	private:
		//engine own message queue - for cross-platform support
		AQUEUE<SystemMessage>	m_messageQueue; 

	protected:
		/* Application data */
		
		HWND		m_hwnd;
		LPCTSTR		m_windowClassName;
		HINSTANCE	m_hInstance;
		ABOOL		m_bWindowed;

		AINT32		m_width;
		AINT32		m_height;

		/* Shutdown */
		ABOOL		m_bQuitting;

		/* Timing */
		Timer*		m_pTimer;
		AREAL64		m_r64LastUpdate;
		AREAL64		m_r64TimeStep;

	public:
		/* Engine subsystems */

		////////////////////////////
		//Renderer
		Renderer	*m_pRenderer;

		////////////////////////////
		//Game Logic
		Game		*m_pGame;

		////////////////////////////
		// Event manager
		Messenger	*m_pMessenger;

		////////////////////////////
		//Game Physics
		IPhysics*	m_pPhysics;
	
	};

	extern Engine *g_pEngine;

}; //namespace Anubis