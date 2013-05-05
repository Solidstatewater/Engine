#pragma once
//========================================================================
// Representation.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Math/Source/Mat4x4.h"
#include "Renderer.h"

namespace Anubis
{
	//Unique identifier for each representation
	typedef AUINT32	EntityRepresentationId;

	//define pointer to the representation
	class EntityRepresentation;
	typedef shared_ptr<EntityRepresentation> EntityRepresentationPtr;

	class Scene;
	class ALIGN16 EntityRepresentation
	{
	protected:

		ALIGN16 Mat4x4 m_currentWorldMatrix;	//matrix in parent space (world matrix for the 1st layer)

		//unique id
		EntityRepresentationId	m_id;

		//time of last update
		AREAL64	m_r64LastUpdate;

		//typedef shared_ptr<EntityRepresentation> EntityRepresentationPtr;
		typedef vector<EntityRepresentation*> Representations;

		//link to the children
		Representations	m_children;

		// ======= Visualization ======= //
		Meshes	m_meshes;
		Lights	m_lights;

	public:
		//Constructor
		EntityRepresentation(EntityRepresentationId id) : m_id(id), m_r64LastUpdate(0.0) {}
		~EntityRepresentation();

		//Add and remove children
		AVIRTUAL AVOID VAddChild(EntityRepresentation* pRepr);
		AVIRTUAL AVOID VRemoveChild(EntityRepresentationId id);

		//Add meshes and lights
		AVIRTUAL AVOID VAddMesh(MeshPtr pMesh);
		AVIRTUAL AVOID VAddLight(LightPtr pLight);

		//find child
		AVIRTUAL EntityRepresentation* VFindChild(EntityRepresentationId  id);

		//put all low-level mesh data to the renderer
		AVIRTUAL AVOID VRender(Scene * pScene, Renderer * pRenderer, AREAL64 r64CurrentTime);

		//	=================  //
		//		Accessors	   //
		//	=================  //
		EntityRepresentationId	GetId() const { return m_id; }

		//	================  //
		//		Mutators	  //
		//	================  //
		AVOID SetCurrentTransform(Mat4x4 & mat, AREAL64 r64CurrentTime);

	protected:

		//pre-rendering modifications
		AVIRTUAL AVOID VPushParameters(Scene *pScene, AREAL64 r64CurrentTime);

		//push data to the renderer
		AVIRTUAL AVOID VSendRenderingData(Scene * pScene, Renderer * pRenderer);

		//undo any changes made to the scene
		AVIRTUAL AVOID VPullParameters(Scene * pScene);

	};

}; //Anubis