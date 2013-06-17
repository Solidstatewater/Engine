#include "Engine_pch.h"
#include "../../../Graphics/Source/Final/General.h"
#include "Engine.h"

using namespace Anubis;

AVOID Engine::InitializeWindow(HINSTANCE hInstance, AINT32 showWnd, AINT32 width, AINT32 height, ABOOL isWindowed)
{
	//assign variables
	m_hInstance = hInstance;
	m_bWindowed = isWindowed;
	m_width = width;
	m_height = height;

	//define struct with window properties
	typedef struct _WNDCLASS {
		AUINT32 cbSize;
		AUINT32 style;
		WNDPROC lpfnWndProc;
		AINT32 cbClsExtra;
		AINT32 cbWndExtra;
		HANDLE hInstance;
		HICON hIcon;
		HCURSOR hCursor;
		HBRUSH hbrBackground;
		LPCTSTR lpszMenuName;
		LPCTSTR lpszClassName;
	} WNDCLASS;

	//fill the WNDCLASS structure
	WNDCLASSEX wc;
	
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = Engine::WndProc;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_windowClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 

	//register window
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Error registering window class",	
			L"Error", MB_OK | MB_ICONERROR);
	}

	HRESULT hr = HRESULT_FROM_WIN32(GetLastError());

	//create window
	m_hwnd = CreateWindowEx(
		NULL,
		m_windowClassName,
		L"TestGame",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		m_width, m_height,
		NULL,
		NULL,
		m_hInstance,
		NULL
		); 

	//check wether window was created correctly
	if (!m_hwnd)
	{
		MessageBox(NULL, L"Error creating window",
			L"Error", MB_OK | MB_ICONERROR);
	}

	//show and update window
	ShowWindow(m_hwnd, showWnd);
	UpdateWindow(m_hwnd);
}

AVOID Engine::InitializeGame(Game * pGame)
{
	//assign pointer to a game class
	m_pGame = pGame;

	//try to initialize it
	if (!pGame->VInitialize())
	{
		assert(0 && "Error initializing the game!");
	}
}

AVOID Engine::InitializeWindowAndGame(HINSTANCE hInstance, AINT32 showWnd, AINT32 width, AINT32 height, ABOOL isWindowed, Game* pGame)
{
	//Initialize window first
	InitializeWindow(hInstance, showWnd, width, height, isWindowed);

	//Initialize game
	InitializeGame(pGame);
}

AVOID Engine::InitializeComponents(Renderer* pRenderer, IPhysics* pPhysics, Messenger* pMessenger)
{
	//initialize messaging system
	m_pMessenger = pMessenger;
	
	//initialize renderer
	m_pRenderer = pRenderer;
	m_pRenderer->VInitialize(m_hwnd, m_width, m_height);

	//Add cameras to the renderer

	const Views * pViews = m_pGame->GetViews();
	for (auto it = pViews->begin(); it != pViews->end(); it++)
	{
		if ((*it)->VHasCamera())
		{
			m_pRenderer->AddCamera((*it)->VGetCamera());
		}
	} 

	//initialize physics
	m_pPhysics = pPhysics;
	m_pPhysics->VInit();
}

LRESULT CALLBACK Engine::WndProc(HWND hwnd, AUINT32 msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_KEYDOWN:
		if( wParam == VK_ESCAPE ){
			DestroyWindow(hwnd);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd,
		msg,
		wParam,
		lParam);
}

ABOOL Engine::MsgProc(SystemMessage * message)
{
	switch (message->m_type)
	{
		case SMT_KeyDown:
		case SMT_KeyUp:
		case SMT_LMouseDown:
		case SMT_LMouseUp:
		case SMT_RMouseDown:
		case SMT_RMouseUp:
		{
			return m_pGame->VMsgProc(message);
		}
		break;
	};
}

AVOID Engine::Update(AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	//If we are in quitting state
	if (m_bQuitting)
	{
		//post WM_CLOSE message to the application
		PostMessage(m_hwnd, WM_CLOSE, 0, 0);
		return;
	}

	if (m_pGame)
		m_pGame->VUpdate(r64Time, r64ElapsedTime);
}

AVOID Engine::Render(AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	m_pGame->VRender(m_pRenderer, r64Time, r64ElapsedTime);
	m_pRenderer->VRender();

	//show back buffer
	PresentBackBuffer();
}

AINT32 Engine::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while(true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/*********************************
			Application received quit message!
			*********************************/
			/*if (msg.message == WM_SYSCOMMAND)
			{
				if (msg.wParam == SC_CLOSE)
				{
					Close();
					break;
				}
			}

			if (msg.message == WM_CLOSE)
			{
				Close();
				break;
			}

			if (msg.message == WM_QUIT)
			{
				if (m_bQuitting)
				{
					Close();
					break;
				}
				else
				{
					m_bQuitting = !m_bQuitting;
				}
			} */

			//Generate system message
			switch (msg.message)
			{                                                                                                                                                                                                                                                                 
			case WM_QUIT:
				//m_messageQueue.push(QuitMessage());
				Close();
				return msg.wParam;
			case WM_KEYDOWN:
				m_messageQueue.push(new KeyDownMessage(msg.wParam));
				break;
			case WM_KEYUP:
				m_messageQueue.push(new KeyUpMessage(msg.wParam));
				break;
			case WM_RBUTTONDOWN:
				m_messageQueue.push(new RMouseDownMessage(LOWORD(msg.lParam), HIWORD(msg.lParam)));
				break;
			case WM_RBUTTONUP:
				m_messageQueue.push(new RMouseUpMessage(LOWORD(msg.lParam), HIWORD(msg.lParam)));
				break;
			case WM_LBUTTONDOWN:
				m_messageQueue.push(new LMouseDownMessage(LOWORD(msg.lParam), HIWORD(msg.lParam)));
				break;
			case WM_LBUTTONUP:
				m_messageQueue.push(new LMouseUpMessage(LOWORD(msg.lParam), HIWORD(msg.lParam)));
				break;
			};

			TranslateMessage(&msg);
			DispatchMessage(&msg);

			while (m_messageQueue.size())
			{
				SystemMessage *pMsg = m_messageQueue.front();
				MsgProc(pMsg);

				m_messageQueue.pop();
				SAFE_DELETE(pMsg);
			};
		}
		else
		{
			/*
				Update Timer
			*/
			m_pTimer->Tick();

			/* ==
				Update with fixed framerate 
										  == */
			AREAL64 r64GameTime = m_pTimer->GetGameTimeSeconds();
			while (r64GameTime - m_r64LastUpdate > m_r64TimeStep)
			{
				Update(m_r64LastUpdate, m_pTimer->GetDeltaTime());
				m_r64LastUpdate += m_r64TimeStep;
			}

			/* ==
				Render
					== */
			Render(r64GameTime, m_pTimer->GetDeltaTime());
		}
	}

	return msg.wParam;
}

AVOID Engine::Close()
{
	SAFE_DELETE(m_pGame);
	CleanUpGraphics();
	SAFE_DELETE(m_pMessenger);
	DestroyWindow(m_hwnd);
	SAFE_DELETE(m_pTimer);
}