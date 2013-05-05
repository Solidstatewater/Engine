#pragma once
//========================================================================
// PointLight.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Light.h"
#include "Final\Resources\Buffers\BufferParams.h"

namespace Anubis
{
	class PointLight : public Light
	{
	protected:

		//define structure with light properties
		//struct PointLightData : public Light::LightData 
		//{
			AREAL32	m_r32Range;

		//	PointLightData(AREAL32 r32Range) : m_range(r32Range)
		//	{
		//	}
		//};

		
		//SpotLightData	m_ldData;

	public:

		//Constructor
		PointLight(const Vec color, const Vec pos, const AREAL32 r32Range) 
			: Light(color, pos, Vector(0.0f, 0.0f, 0.0f, 1))
		{
			m_r32Range = r32Range;
		};


		/**
			== Rendering ==
							**/
		AVOID VPreRender(Renderer *pRenderer);
		//AVOID VRender();

		/**
			== Getters ==
							**/
		AVIRTUAL LightType VGetType() const { return LT_Point; }

		//Vec GetPosition() const { return m_pos; }
	};

}; //Anubis