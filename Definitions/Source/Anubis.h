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
/*#ifdef WIN32
	struct AppMsg
	{
		HWND	m_hWnd;
		UINT	m_uMsg;
		WPARAM	m_wParam;
		LPARAM	m_lParam;
	};
#endif //WIN32 */
	enum SystemMessageType
	{
		SMT_Quit,
		SMT_KeyDown,
		SMT_KeyUp,
		SMT_LMouseDown,
		SMT_LMouseUp,
		SMT_RMouseDown,
		SMT_RMouseUp,
		SMT_MouseMove,
	};

	struct SystemMessage
	{
		SystemMessageType	m_type;
	};

	struct QuitMessage : public SystemMessage
	{
		explicit QuitMessage()
		{
			m_type = SMT_Quit;
		}
	};

	struct KeyboardMessage : public SystemMessage
	{
		ACHAR m_key;

		KeyboardMessage(const CHAR key)
		{
			m_key = key;
		}
	};

	struct KeyDownMessage : public KeyboardMessage
	{
		explicit KeyDownMessage(const ACHAR key) : KeyboardMessage(key)
		{
			m_type = SMT_KeyDown;
		}
	};

	struct KeyUpMessage : public KeyboardMessage
	{
		explicit KeyUpMessage(const ACHAR key) : KeyboardMessage(key)
		{
			m_type = SMT_KeyUp;
		}
	};

	struct MouseMessage : public SystemMessage
	{
		AREAL	m_posx;
		AREAL	m_posy;

		MouseMessage(const AREAL x, const AREAL y) 
		{
			m_posx = x;
			m_posy = y;
		}
	};

	struct LMouseDownMessage : public MouseMessage
	{
		explicit LMouseDownMessage(const AREAL x, const AREAL y) : MouseMessage(x, y)
		{
			m_type =	SMT_LMouseDown;
		}
	};

	struct LMouseUpMessage : public MouseMessage
	{
		explicit LMouseUpMessage(const AREAL x, const AREAL y) : MouseMessage(x, y)
		{
			m_type =	SMT_LMouseUp;
		}
	};

	struct RMouseDownMessage : public MouseMessage
	{
		explicit RMouseDownMessage(const AREAL x, const AREAL y) : MouseMessage(x, y)
		{
			m_type =	SMT_RMouseDown;
		}
	};

	struct RMouseUpMessage : public MouseMessage
	{
		explicit RMouseUpMessage(const AREAL x, const AREAL y) : MouseMessage(x, y)
		{
			m_type =	SMT_RMouseUp;
		}
	};

	struct MouseMoveMessage : public MouseMessage
	{
		explicit MouseMoveMessage(const AREAL x, const AREAL y) : MouseMessage(x, y)
		{
			m_type =	SMT_MouseMove;
		}
	};

}; //Anubis

//#define SCREEN_WIDTH 1920
//#define SCREEN_HEIGHT 1080