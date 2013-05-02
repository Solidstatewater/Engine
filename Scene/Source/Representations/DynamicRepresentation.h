#pragma once
//========================================================================
// DynamicRepresentation.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../Scene.h"

namespace Anubis
{
	// ============================================= //
	//	For objects which can affect the game state  //
	// ============================================= //
	class DynamicRepresentation : public EntityRepresentation
	{
	protected:
		Mat4x4	m_prevWorldMatrix;

	public:
		//constructor
		DynamicRepresentation(EntityRepresentationId id) : EntityRepresentation(id)
		{
		}

	protected:

		//pre-rendering modifications
		AVIRTUAL AVOID VPushParameters(Scene *pScene, AREAL64 r64CurrentTime);
	};
}; //Anubis