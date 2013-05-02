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
		ShaderBunch() {}

		//Shaders
		AVIRTUAL AVOID VSetVertexShader		(AWSTRING fileName, ASTRING shaderName, INPUT_LAYOUT* layout, AUINT8 num, AUINT16 topology);
		AVIRTUAL AVOID VSetHullShader		(AWSTRING fileName, ASTRING shaderName);
		AVIRTUAL AVOID VSetDomainShader		(AWSTRING fileName, ASTRING shaderName);
		AVIRTUAL AVOID VSetGeometryShader	(AWSTRING fileName, ASTRING shaderName);
		AVIRTUAL AVOID VSetPixelShader		(AWSTRING fileName, ASTRING shaderName);

		AVIRTUAL AVOID VBind();
	}; 
}; //Anubis