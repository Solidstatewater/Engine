#pragma once
//========================================================================
// SpotLight.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Light.h"

namespace Anubis
{
	class SpotLight : public Light
	{
	protected:

		//define structure with light properties
		//struct SpotLightData : public Light::LightData 
		//{
			AREAL32 m_r32InnerAngleInRadians;
			AREAL32 m_r32OuterAngleInRadians;

		//	SpotLightData(AREAL32 r32InnerAngleInRadians, AREAL32 r32OuterAngleInRadians)
		//		: m_r32InnerAngleInRadians(r32InnerAngleInRadians), m_r32OuterAngleInRadians(r32OuterAngleInRadians)
		//	{
		//	}
		//};

		//SpotLightData m_ldData;

	public:

		//Constructor
		SpotLight  (const Vec& color, const Vec& pos, const Vec& dir,
					AREAL32 r32InnerAngleInRadians, AREAL32 r32OuterAngleInRadians)
					: Light(color, pos, dir)
		{
			m_r32InnerAngleInRadians = r32InnerAngleInRadians;
			m_r32OuterAngleInRadians = r32OuterAngleInRadians;
		}

		/**
			== Getters ==
							**/
		AVIRTUAL LightType VGetType()	const { return LT_Spot; }

		//Vec GetPosition()				const { return m_pos; }
		//Vec GetDirection()				const { return m_dir; }
		//AREAL32 GetInnerAngle()			const { return m_r32InnerAngleInRadians; }
		//AREAL32 GetOuterAngle()			const { return m_r32OuterAngleInRadians; }
	};

}; //Anubis