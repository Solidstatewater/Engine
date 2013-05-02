#pragma once
//========================================================================
// Base.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../Math/Source/Mat4x4.h"
#include "Representations\Representation.h"

namespace Anubis
{
	//Unique identifier for each game actor
	typedef AUINT32	EntityId;

	class IPhysics;
	class Entity
	{
	protected:
		//unique id for each entity
		EntityId	m_id;

		//entity transformation matrix
		Mat4x4		m_prevWorldMatrix;
		Mat4x4		m_currentWorldMatrix;

		//pointer to its representation
		EntityRepresentation *	m_pRepresentation;

	public:
		//constructor
		Entity(EntityId id) : m_id(id), m_prevWorldMatrix(Mat4x4::Identity()), m_currentWorldMatrix(Mat4x4::Identity()) {}
		/***** Initializing *****/
		//AVIRTUAL EntityRepresentationPtr VCreateRepresentation(Scene * pScene) = 0;

		//create its physics model
		//AVIRTUAL AVOID VCreatePhysicalBody(IPhysics * pPhysics) = 0;

		/***** Accessors *****/
		EntityId	GetId() const { return m_id; } //return entity id
		Mat4x4		GetGurrentTransform() const { return m_currentWorldMatrix; }
		EntityRepresentation * GetRepresentation() const { return m_pRepresentation; }

		/***** Mutators *****/
		AVOID		SetCurrentTransform(Mat4x4 const & transform)	{ m_currentWorldMatrix = transform; }

		/***** Updating *****/
		AVIRTUAL AVOID	VUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime);

	private:
		//AVIRTUAL AVOID VPreUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime);
		//AVIRTUAL AVOID VPostUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime);
	};

	//define Entity pointer
	typedef shared_ptr<Entity>	EntityPtr;

}; //Anubis