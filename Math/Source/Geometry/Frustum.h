#pragma once
//========================================================================
// Frustum.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Plane.h"

namespace Anubis
{
	class Frustum
	{
	public:
		enum Side { Near, Far, Top, Right, Bottom, Left, NumPlanes };

		Plane	m_planes[NumPlanes];	// planes of the frusum in camera space
		Vec		m_nearClip[4];			// verts of the near clip plane in camera space
		Vec		m_farClip[4];			// verts of the far clip plane in camera space

		AREAL m_fov;				// field of view in radians
		AREAL m_aspect;				// aspect ratio - width divided by height
		AREAL m_near;				// near clipping distance
		AREAL m_far;				// far clipping distance

	public:

		//constructor
		Frustum();
		~Frustum();

		/**
				Initializers
								**/
		AVOID Init(const AREAL fov, const AREAL aspect, const AREAL near, const AREAL far);

		/**
				Methods
							**/
		ABOOL Inside(const Vec & point) const;
		ABOOL Inside(const Vec & point, const AREAL radius) const;

		/**
				Getters
							**/
		const Plane &	Get(Side side)		const { return m_planes[side]; }
		const AREAL		GetFOV()			const { return m_fov; }
		const AREAL		GetAspectRatio()	const { return m_aspect; }
		const AREAL		GetNearZ()			const { return m_near; }
		const AREAL		GetFarZ()			const { return m_far; }

		/**
				Mutators
							**/
		AVOID SetFOV(AREAL fov)			{ m_fov=fov;		Init(m_fov, m_aspect, m_near, m_far); }
		AVOID SetAspect(AREAL aspect)	{ m_aspect=aspect;	Init(m_fov, m_aspect, m_near, m_far); }
		AVOID SetNear(AREAL nearClip)	{ m_near=nearClip;	Init(m_fov, m_aspect, m_near, m_far); }
		AVOID SetFar(AREAL farClip)		{ m_far=farClip;	Init(m_fov, m_aspect, m_near, m_far); }

		void Render();
	};
};