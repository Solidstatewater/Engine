#pragma once
//========================================================================
// StateFactory.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "State.h"

namespace Anubis
{
	/** =========================
		   Creates Game States
	    ========================= **/
	class StateFactory
	{
	public:
		/**
			Returns pointer to created game state or NULL
			if it couldn't be created
															**/
		AVIRTUAL State * VCreateState(AINT32 i32Id) const;
	};

}; //Anubis