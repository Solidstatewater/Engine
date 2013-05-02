#pragma once

#include "Error_Handling\Assert.h"

#include "Strings\HashedString.h"

#include "Defines.h"
#include "Types.h"
#include "Conventions.h"
#include "Conversions.h"
#include "Casting.h"

namespace Anubis
{
	//Struct for storing OS message data
#ifdef WIN32
	struct AppMsg
	{
		HWND	m_hWnd;
		UINT	m_uMsg;
		WPARAM	m_wParam;
		LPARAM	m_lParam;
	};
#endif //WIN32
}; //Anubis

//#define SCREEN_WIDTH 1920
//#define SCREEN_HEIGHT 1080