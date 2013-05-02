#pragma once
//========================================================================
// Controllers.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Devices.h"

namespace Anubis
{

	class PCPlayerController : public IMouseHandler, public IKeyboardHandler
	{
	protected:

		//key codes
		Key				m_bKey[256];

		//previous mouse position
		CPoint			m_prevMousePos;

	public:

	};

}; //Anubis