#pragma once
//========================================================================
// PhysicsInterface.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	//******************************************
	// Represents Interface to hold game physics
	//******************************************
	class IPhysics
	{
	public:

		/////////////////////////
		/*** General Methods ***/
		/////////////////////////

		//Initialize physics
		AVIRTUAL ABOOL VInit() = 0;
		
		//Update simulation
		AVIRTUAL AVOID VUpdate() = 0;

		///////////////////////////////////////
		/*** Add objects to the simulation ***/
		///////////////////////////////////////

		/////////////////////////////////////
		/*** Apply actions to the bodies ***/
		/////////////////////////////////////
	};
};