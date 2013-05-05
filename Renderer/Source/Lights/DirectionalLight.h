#pragma once
//========================================================================
// DirectionalLight.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Light.h"

namespace Anubis
{
	class ALIGN16 DirectionalLight : public Light
	{
	protected:

		//define structure with light properties
		//struct DirectionalLightData : public Light::LightData 
		//{
		//};

		//DirectionalLightData	m_ldData;

	public:

		//Constructor
		DirectionalLight(const Vec& color, const Vec& pos, const Vec& dir) : Light(color, pos, dir)
		{
		};

		/**
			== Getters ==
							**/
		AVIRTUAL LightType VGetType() const { return LT_Directional; }

		//Vec GetDirection() const { return m_dir; }
	};

}; //Anubis