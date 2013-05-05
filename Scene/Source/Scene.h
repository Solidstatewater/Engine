#pragma once
//========================================================================
// Scene.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../Math/Source/Mat4x4.h"

#include "Renderer.h"

#include "Representations\Representation.h"
#include "Representations\Root.h"

namespace Anubis
{
	class ALIGN16 Scene
	{
	protected:
		//store current transform
		ALIGN16 MatrixStack	m_transforms;

		//root node
		ALIGN16 RootRepresentation*	m_pRoot;

		//fixed time step
		AREAL64	m_r64FixedTimeStep;

	public:
		//Constructor and Destructor
		Scene();
		~Scene();

		/***	====	Initialization	====	***/
		AVIRTUAL ABOOL VInitialize();

		/***	====	Updating	====	***/
		AVIRTUAL AVOID VUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime);

		/***	====	Rendering	====	***/
		AVIRTUAL AVOID VRender(Renderer * pRenderer, AREAL64 r64CurrentTime);

		//Representations management
		EntityRepresentation* GetRepresentation(EntityRepresentationId id);
		ABOOL RemoveRepresentation(EntityRepresentationId id);
		AVOID AddRepresentation(EntityRepresentation* pRepresentation,
			RenderPass pass = RenderPass_Actors, EntityRepresentationId parentId = 0);

		//update current world transform
		AVOID PushTransform(const Mat4x4 & mat);

		//get current tranform
		Mat4x4 GetTransform() const;

		//remove last transform
		AVOID PullTransform();

		//	=============  //
		//	Accessors
		//	=============  //
		AREAL64 GetFixedTimeStep() const { return m_r64FixedTimeStep; }
	};
};