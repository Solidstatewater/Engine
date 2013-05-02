#pragma once
//========================================================================
// ComputeShaderDX11.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../Other/BlobDX11.h"

namespace Anubis
{
	class ComputeShaderDX11
	{
	protected:
		ID3D11ComputeShader*	m_pShader;

	public:
		ComputeShaderDX11() { m_pShader = NULL;}
		~ComputeShaderDX11() { SAFE_RELEASE(m_pShader); }

		AVOID Set() const;

		ABOOL Create(BlobDX11 & shaderbuffer);
		ABOOL CreateAndCompile(AWSTRING fileName, ASTRING entrypoint, BlobDX11 * pErrors = NULL);
	};
}; //Anubis