#pragma once
//========================================================================
// Views.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Renderer.h"
#include "Messenger.h"
#include "Widget.h"

namespace Anubis
{
	class IView
	{
	public:
		AVIRTUAL ~IView() {}

		AVIRTUAL ABOOL		VInit()												= 0;
		AVIRTUAL ABOOL		VRestore()											= 0;
		AVIRTUAL AVOID		VUpdate(AUINT32 const deltaMilliseconds)			= 0;
		AVIRTUAL AVOID		VRender(AREAL64 r64Time, AREAL64 r64ElapsedTime)	= 0;
		AVIRTUAL ABOOL	VMsgProc(SystemMessage & msg)						= 0;

		AVIRTUAL	AVOID	  VSetCamera(CameraPtr pCamera) = 0;
		AVIRTUAL	CameraPtr VGetCamera() const = 0;
		AVIRTUAL	ABOOL	  VHasCamera() const = 0;
	};

	class PlayerView : public IView
	{
	protected:

	public:
		PlayerView() : m_bHasCamera(false) {}
		AVIRTUAL ~PlayerView() { }

		AVIRTUAL ABOOL		VInit();
		AVIRTUAL ABOOL		VRestore();
		AVIRTUAL AVOID		VUpdate(AUINT32 const deltaMilliseconds);
		AVIRTUAL AVOID		VRender(AREAL64 r64Time, AREAL64 r64ElapsedTime);
		AVIRTUAL ABOOL		VMsgProc(SystemMessage & msg);

	protected:
		/* ==================================
		//	Widgets
		=================================== */
		Widgets m_widgets;

		/* ==================================
		// Game Rendering
		=================================== */
		CameraPtr	m_pCamera;
		ABOOL		m_bHasCamera;

		ALIGN16 AREAL32 bgColor[4];

	public:

		//Widgets
		AVIRTUAL AVOID AddWidget(WidgetPtr pWidget);
		AVIRTUAL ABOOL RemoveWidget(WidgetPtr pWidget);

		//Game Rendering
		AVIRTUAL AVOID VSetCamera(CameraPtr pCamera);
		AVIRTUAL CameraPtr VGetCamera() const { return m_pCamera; }
		AVIRTUAL ABOOL VHasCamera() const { return m_bHasCamera; }

	};

	//typedefs
	typedef shared_ptr<IView>	ViewPtr;
	typedef vector<ViewPtr>		Views;

}; //Anubis