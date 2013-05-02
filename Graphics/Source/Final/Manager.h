#pragma once
//========================================================================
// Manager.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../DX11/DX11Manager.h"

namespace Anubis
{
	class GraphicsManager : public
		#ifdef ADX11_API
			DX11Manager
		#endif
	{
	};
}; //Anubis