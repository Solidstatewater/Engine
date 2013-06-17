#pragma once
//========================================================================
// Controllers.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Devices.h"
#include "../../Math/Source/Math_pch.h"

namespace Anubis
{
	class MovementController
	{
	public:
		AVIRTUAL AREAL	VGetTargetYawRot()		const	{ return 0.0f; }
		AVIRTUAL AREAL	VGetTargetPitchRot()	const	{ return 0.0f; }
		AVIRTUAL AREAL	VGetTargetRoll()		const	{ return 0.0f; }
		AVIRTUAL AREAL	VGetTargetAngularSpeed()const	{ return 0.0f; }
		AVIRTUAL AREAL	VGetTargetSpeed()		const	{ return 0.0f; }
		AVIRTUAL Vec	VGetTargetVelocity()	const	{ return Vector(0.0f, 0.0f, 0.0f, 0.0f); }

		AVIRTUAL AVOID VUpdate(AINT32 const deltaMs) {}
	};

	class PCPlayerController : public IMouseHandler, public IKeyboardHandler
	{
	protected:

		//key codes
		Key				m_bKey[256];

		//previous mouse position
		float2			m_prevMousePos;

	public:

		PCPlayerController()
			{
				for (auto i = 0; i < 256; i++)
				{
					m_bKey[i] = false;
				}
			}

		ABOOL VOnLButtonDown(const AREAL x, const AREAL y)	{ return true; }
		ABOOL VOnLButtonUp(const AREAL x, const AREAL y)	{ return true; }

		ABOOL VOnRButtonDown(const AREAL x, const AREAL y)	{ return true; }
		ABOOL VOnRButtonUp(const AREAL x, const AREAL y)	{ return true; }

		ABOOL VOnMouseMove(const AREAL x, const AREAL y)	{ return true; }

		ABOOL VOnKeyDown(Key const key)
			{
				m_bKey[key] = true;

				return true;
			}
		ABOOL VOnKeyUp(Key const key)
			{
				m_bKey[key] = false;

				return true;
			}
	};

	class FreeCameraController : public PCPlayerController, public MovementController
	{
	protected:
		AREAL	m_r32TargetYawRot;
		AREAL	m_r32TargetPitchRot;
		AREAL	m_r32TargetRollRot;
		//AREAL	m_r32Yaw;
		//AREAL	m_r32Pitch;
		//AREAL	m_r32Roll;
		
		AREAL	m_r32MaxSpeed;
		AREAL	m_r32AngularSpeed;
		AREAL	m_r32CurrentSpeed;
		AREAL	m_r32TargetSpeed;
		Vec		m_vTargetVelocity;

	public:

		//Contructor
		FreeCameraController()
			{
				m_r32TargetYawRot = 0.0f;
				m_r32TargetPitchRot = 0.0f;
				m_r32TargetRollRot = 0.0f;

				m_r32TargetSpeed = 1.0f;
				m_vTargetVelocity = Vector(0.0f, 0.0f, 0.0f, 0.0f);
			}

		// Mouse Handler Implementation //
		ABOOL VOnMouseMove(const AREAL x, const AREAL y)
			{
				if (x != m_prevMousePos.x || y != m_prevMousePos.y)
				{
					m_r32TargetYawRot = (m_prevMousePos.x - x);
					m_r32TargetPitchRot = (y - m_prevMousePos.y);
					m_prevMousePos.x = x;
					m_prevMousePos.y = y;
				}

				return true;
			}

		//Keyboard handler Implementation //

		// Movement controller implementation //
		AREAL	VGetTargetYawRot()		const	{ return m_r32TargetYawRot; }
		AREAL	VGetTargetPitchRot()	const	{ return m_r32TargetPitchRot; }
		AREAL	VGetTargetRollRot()		const	{ return m_r32TargetRollRot; }
		AREAL	VGetTargetSpeed()		const	{ return m_r32TargetSpeed; }
		Vec 	VGetTargetVelocity()	const	{ return m_vTargetVelocity; }

		AVOID VUpdate(AINT32 const deltaMs)
			{
				if (m_bKey['W'])
				{
					m_vTargetVelocity = g_forward4 * m_r32TargetSpeed;
				}
				if (m_bKey['S'])
				{
					m_vTargetVelocity = g_back4 * m_r32TargetSpeed;
				}
				if (m_bKey['A'])
				{
					m_vTargetVelocity = g_left4 * m_r32TargetSpeed;
				}
				if (m_bKey['D'])
				{
					m_vTargetVelocity = g_right4 * m_r32TargetSpeed;
				}
			}
	};
}; //Anubis