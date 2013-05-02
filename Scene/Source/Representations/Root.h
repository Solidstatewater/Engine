#pragma once
//========================================================================
// Root.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Representation.h"

namespace Anubis
{
	//enumaration for render passes
	enum RenderPass
	{
		RenderPass_Static,
		RenderPass_Actors,
		NUM_RENDER_PASSES,
	};

	//	=====	Root Node for the scene	=====	//
	class ALIGN16 RootRepresentation : public EntityRepresentation
	{
	protected:
		//devide all objects on different render passes
		Representations m_passes[NUM_RENDER_PASSES];

	public:
		//constructor
		RootRepresentation();

		//Add and remove children
		AVIRTUAL AVOID VAddChild(EntityRepresentation* pRepr, RenderPass pass, EntityRepresentationId parentId);
		AVIRTUAL AVOID VRemoveChild(EntityRepresentationId id);

		//find child
		AVIRTUAL EntityRepresentation* VFindChild(EntityRepresentationId id);
		EntityRepresentation* FindChild(EntityRepresentationId id, RenderPass pass);

		//put all low-level mesh data to the renderer
		AVIRTUAL AVOID VRender(Scene * pScene, Renderer * pRenderer, AREAL64 r64CurrentTime);

	};

}; //Anubis