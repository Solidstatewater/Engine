#pragma once
//========================================================================
// Light.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../Other/ShaderBunch.h"
#include "../../Math/Source/Vectors.h"
#include "Final\Resources\Buffers\BufferParams.h"
#include "Final\Resources\Buffers\Buffers.h"
#include "../Renderer_pch.h"

namespace Anubis
{
	//Light Types
	enum LightType
	{
		LT_Point		= 1,
		LT_Spot			= 2,
		LT_Directional	= 3,
	};

	/************************************************************
	============= Class with basic light properties =============
	************************************************************/
	class Renderer;
	class ALIGN16 Light
	{
	protected:

		ABOOL m_bInitialized;

		/*** Light Shader ***/
		AWSTRING m_shaderFile;
		ShaderBunch*	m_pShaders;

		/*** Constant Buffer With Light Data ***/
		//ConstantBuffer*	m_pBuffer; 

		/**				
			== Light Data ==
								**/
	
		struct LightData //define structure with light properties
		{
			Vec m_color;
			Vec m_pos;
			Vec m_dir;
		};

		LightData* m_pData;

	public:

		//Constructor
		Light(const AWSTRING & shaderFile = DEFAULT_LIGHT_PASS_SHADER_FILE) : m_bInitialized(false)
		{
			m_pShaders = NULL;

			m_shaderFile = shaderFile;
		}
		Light(const Vec& color, const Vec& pos, const Vec& dir,
			const AWSTRING & shaderFile = DEFAULT_LIGHT_PASS_SHADER_FILE) : m_bInitialized(false)
		{
			m_pShaders = NULL;

			m_shaderFile = shaderFile;

			m_pData = new LightData();
			FillBasicProperties(color, pos, dir);
		}
		~Light() { SAFE_DELETE(m_pData); }

		AVIRTUAL ABOOL VInitialize(INPUT_LAYOUT * pLayout);

		//Fill with data
		AVOID FillBasicProperties(const Vec& color, const Vec& pos, const Vec& dir)
		{
			m_pData->m_color = color;
			m_pData->m_pos = pos;
			m_pData->m_dir = dir;
		}

		/**
			== Getters ==
							**/
		ABOOL IsInitialized() const { return m_bInitialized; }

		//Get color
		//Vec VGetColor() const { return m_ldCommonData.m_color; }

		//Get light type
		AVIRTUAL LightType VGetType() const = 0;

		/**
			== Rendering ==
							**/
		AVIRTUAL AVOID VPreRender(Renderer *pRenderer);
		AVIRTUAL AVOID VRender();
	};

	typedef shared_ptr<Light>	LightPtr;
	typedef vector<LightPtr>	Lights;

}; //Anubis