#pragma once
//========================================================================
// Physics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../PhysicsInterface.h"

namespace Anubis
{

	class HavokPhysics : public IPhysics
	{
	public:

		/**********************************
		//	Implement IPhysics Interface
		**********************************/

		//Initialize physics
		AVIRTUAL ABOOL VInit();
		
		//Update simulation
		AVIRTUAL AVOID VUpdate();
	};

	HavokPhysics* CreateHavokPhysics();

}; //Anubis