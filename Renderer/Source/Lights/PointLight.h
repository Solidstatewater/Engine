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
		struct PointLightData : public Light::LightData 
		{
			AREAL32	m_range;

			PointLightData(AREAL32 r32Range) : m_range(r32Range)
			{
			}
		};
		
		//SpotLightData	m_ldData;

	public:

		//Constructor
		PointLight(const Vec color, const Vec pos, const AREAL32 r32Range) : Light()
		{
			m_pData = new PointLightData(r32Range);

			//set basic properties
			FillBasicProperties(color, pos, Vector(0, 0, 0, 0));

			//Create constant buffer
			BufferParams params;
			params.FillConstantBufferParams(sizeof(PointLightData), true, false, false);
			m_pBuffer->Create(&params, NULL);
		};


		/**
			== Rendering ==
							**/
		AVOID VPreRender();
		//AVOID VRender();

		/**
			== Getters ==
							**/
		AVIRTUAL LightType VGetType() const { return LT_Point; }

		//Vec GetPosition() const { return m_pos; }
	};

}; //Anubis