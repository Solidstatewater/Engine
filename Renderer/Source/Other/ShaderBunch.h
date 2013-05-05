#pragma once
//========================================================================
// ShaderBunch.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Final\Stages\Shaders\Shaders.h"

namespace Anubis
{
	// =========================================
	//	Use this class to make pipeline bunches
	//	programmable stages
	// =========================================
	class ShaderBunch
	{
	private:
		VertexShaderPtr	m_pVertexShader;
		PixelShaderPtr	m_pPixelShader;

	public:
		//constructor
		ShaderBunch() {
			m_pVertexShader = nullptr;
			m_pPixelShader = nullptr;
		}

		//Shaders
		AVIRTUAL AVOID VSetVertexShader		(const AWSTRING & fileName, const ASTRING & shaderName, INPUT_LAYOUT* layout,
											 AUINT8 num, AUINT16 topology);
		AVIRTUAL AVOID VSetHullShader		(const AWSTRING & fileName, const ASTRING & shaderName);
		AVIRTUAL AVOID VSetDomainShader		(const AWSTRING & fileName, const ASTRING & shaderName);
		AVIRTUAL AVOID VSetGeometryShader	(const AWSTRING & fileName, const ASTRING & shaderName);
		AVIRTUAL AVOID VSetPixelShader		(const AWSTRING & fileName, const ASTRING & shaderName);

		AVIRTUAL AVOID VBind();
	}; 
}; //Anubis