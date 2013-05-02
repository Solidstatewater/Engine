#pragma once
//========================================================================
// Camera.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Math/Source/Geometry/Frustum.h"
#include "Final/Other/Viewport.h"

namespace Anubis
{
	class ALIGN16 Camera
	{
	protected:
		/**
			View and Projection matrices
											**/
		Mat4x4	m_view;
		Mat4x4	m_projection;

		/**
			General Data
						 **/

		Vec	m_pos;		//position
		Vec m_dir;		//direction of the camera
		Vec	m_lookAt;	//point camera is looking at
		Vec m_up;		//direction of up vector

		AREAL m_yaw;
		AREAL m_pitch;
		AREAL m_roll;

		/**
			Projection Data
							**/
		Frustum	m_frustum;


		//Viewport to render to
		Viewport*	m_pViewport;

		/**
			Other Data
						**/
		ABOOL	m_bActive;
		ABOOL	m_bDebug;

		/** ===============================
					Methods
		=============================== **/
		AVOID UpdateTransforms();

	public:

		//Constructor and destructor
		Camera(	const Frustum & frustum,
				Vec & position, Vec & dir, Vec & up,
				AREAL yaw, AREAL pitch, AREAL roll,
				Viewport * pViewport = NULL);
		~Camera();

		/*==
				Mutators
								==*/
		AINLINE AVOID SetActive(ABOOL isActive) { m_bActive = isActive; }

		/*==
				Accessors
								==*/

		AINLINE ABOOL IsActive() const { return m_bActive; }

		//AVIRTUAL HRESULT SetViewTransform(Scene *pScene);

		AINLINE const Frustum &GetFrustum() { return m_frustum; }

		AINLINE Mat4x4	GetProjection()		const { return m_projection; }
		AINLINE Mat4x4	GetView()			const { return m_view; }
		AINLINE Mat4x4&	GetViewProjection()	const { return m_view * m_projection; }

		AINLINE Mat4x4	GetOrthoProjection() const;

		AINLINE Vec		GetPosition()		const { return m_pos; }

		AINLINE AREAL	GetRoll()			const { return m_roll; }
		AINLINE AREAL	GetPitch()			const { return m_pitch; }
		AINLINE AREAL	GetYaw()			const { return m_yaw; }

		/*==
				Methods
								==*/
		AVIRTUAL AVOID VUpdate(AUINT32 const elapsedMs);
	};

	//typedefs
	typedef shared_ptr<Camera>	CameraPtr;
	typedef vector<CameraPtr>	Cameras;
};