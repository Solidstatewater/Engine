#include "Game_pch.h"
#include "Views.h"

#include "../../../Graphics/Source/Final/General.h"

using namespace Anubis;

ABOOL PlayerView::VInit()
{
	/*** Create Renderer
	//
	// Implementation at Renderer project
	//
	***/
	//m_pDeferredRenderer = new DeferredRenderer();

	bgColor[0] = 1.0f;
	bgColor[1] = 1.0f;
	bgColor[2] = 1.0f;
	bgColor[3] = 1.0f;

	return true;
}

ABOOL PlayerView::VRestore()
{ 
	return true;
}

AVOID PlayerView::VUpdate(AUINT32 const deltaMilliseconds)
{
	//Update widgets
	for (Widgets::iterator it = m_widgets.begin(); it != m_widgets.end(); it++)
	{
		(*it)->VUpdate(deltaMilliseconds);
	}
}

AVOID PlayerView::VRender(Renderer *pRenderer, AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	//Clean back buffer render target and depth stencil
	//ALIGN16 AREAL32 bgColor[4] = { 0.0f, 1.0f, 1.0f, 1.0f }; //color
	ALIGN16 AREAL32 bg[4] = { 1.0f, 0.0f, 1.0f, 1.0f };
	ClearRenderTargetView(bg, NULL);
	ClearDepthStencilView(true, true, 1.0f, 0, NULL);

	//render widgets
	for (Widgets::iterator it = m_widgets.begin(); it != m_widgets.end(); it++)
	{
		(*it)->VRender(pRenderer, r64Time, r64ElapsedTime);
	}
}

ABOOL PlayerView::VMsgProc(SystemMessage & msg)
{
	//Use reverse_iterator as widgets process messages
	//from top of screen to bottom
	for (Widgets::reverse_iterator it = m_widgets.rbegin(); it != m_widgets.rend(); it++)
	{
		if ((*it)->VMsgProc(msg))
			return true;
	}

	//no widget processed a message, so give controllers a try
	ABOOL res = false;
	switch(msg.m_type)
	{

	case SMT_KeyDown:
		if (m_pKeyboardHandler)
		{
			AUINT8 key = static_cast<KeyDownMessage &>(msg).m_key;
			res = m_pKeyboardHandler->VOnKeyDown(key);
		}
		break;

	case SMT_KeyUp:
		if (m_pKeyboardHandler)
		{
			AUINT8 key = static_cast<KeyUpMessage &>(msg).m_key;
			res = m_pKeyboardHandler->VOnKeyUp(key);
		}
		break;

	case SMT_MouseMove:
		if (m_pMouseHandler)
		{
			AREAL posx = static_cast<MouseMoveMessage &>(msg).m_posx;
			AREAL posy = static_cast<MouseMoveMessage &>(msg).m_posy;
			res = m_pMouseHandler->VOnMouseMove(posx, posy);
		}
		break;

	case SMT_LMouseDown:
		if (m_pMouseHandler)
		{
			AREAL posx = static_cast<LMouseDownMessage &>(msg).m_posx;
			AREAL posy = static_cast<LMouseDownMessage &>(msg).m_posy;

			res = m_pMouseHandler->VOnRButtonDown(posx, posy);
		}
		break;

	case SMT_LMouseUp:
		if (m_pMouseHandler)
		{
			AREAL posx = static_cast<LMouseUpMessage &>(msg).m_posx;
			AREAL posy = static_cast<LMouseUpMessage &>(msg).m_posy;

			res = m_pMouseHandler->VOnLButtonUp(posx, posy);
		}
		break;

	case SMT_RMouseDown:
		if (m_pMouseHandler)
		{
			AREAL posx = static_cast<RMouseDownMessage &>(msg).m_posx;
			AREAL posy = static_cast<RMouseDownMessage &>(msg).m_posy;

			res = m_pMouseHandler->VOnRButtonDown(posx, posy);
		}
		break;

	case SMT_RMouseUp:
		if (m_pMouseHandler)
		{
			AREAL posx = static_cast<RMouseUpMessage &>(msg).m_posx;
			AREAL posy = static_cast<RMouseUpMessage &>(msg).m_posy;

			res = m_pMouseHandler->VOnRButtonDown(posx, posy);
		}
		break;
	};

	return res;
}

AVOID PlayerView::VSetCamera(CameraPtr pCamera)
{
	m_pCamera = pCamera;
	m_bHasCamera = true;
}

AVOID PlayerView::AddWidget(WidgetPtr pWidget)
{
	m_widgets.push_back(pWidget);
}

ABOOL PlayerView::RemoveWidget(WidgetPtr pWidget)
{
	for( Widgets::iterator it = m_widgets.begin(); it != m_widgets.end(); it++)
	{
		if ((*it) == pWidget)
		{
			m_widgets.erase(it);
			return true;
		}
	}
	
	return false;
	//assert(0 && "No such widget was found!!!");
}