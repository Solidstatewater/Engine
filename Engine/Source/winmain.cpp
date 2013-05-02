#include "Engine_pch.h"
#include "Application\Engine.h"

using namespace Anubis;

////////////////////////////////////
//Entry point for the application
////////////////////////////////////
INT WINAPI GameMain(HINSTANCE hInstance, 
					HINSTANCE hPrevInstance,
					LPWSTR lpCmdLine,
					int	   nCmdShow)
{
	//set semo debuggin flags
	int debugFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	debugFlag	|=	_CRTDBG_LEAK_CHECK_DF;
	debugFlag	|=	_CRTDBG_CHECK_ALWAYS_DF;
	debugFlag	|=	_CRTDBG_DELAY_FREE_MEM_DF;

	_CrtSetDbgFlag(debugFlag);

	//now set main callback methods
	//AUTSetCallbackOnCreateDevice((PCALLBACKONCREATEDEVICE)GameApp::OnCreateDevice);
	//AUTSetCallbackOnRelease( (PCALLBACKONRELEASE)GameApp::OnDestroyDevice ); //ýòî èäåíòè÷íEDeviceDestroyed???
	//DXUTSetCallbackMsgProc( GameApp::OnMsgProc );
	//DXUTSetCallbackD3D11FrameRender( (LPDXUTCALLBACKD3D11FRAMERENDER)GameApp::OnRender );   //Ãäå ýòè EEåêE! ^^
	//AUTSetCallbackOnFrameProcess( (PCALLBACKONFRAMEPROCESS)GameApp::OnUpdate );

	//initialize out application
	//if (true != g_pApp->VInitialize(hInstance, lpCmdLine))
	{
		return false;
	}

	//run DXUT framework
	//AUTMainLoop();
	//AUTShutdown();

	//return g_pApp->ExitCode();
	return 0;
}