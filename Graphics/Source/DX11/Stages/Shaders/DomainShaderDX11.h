#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../Other/BlobDX11.h"

namespace Anubis
{
	class DomainShaderDX11
	{
	protected:
		ID3D11DomainShader*	m_pShader;

	public:
		DomainShaderDX11() { m_pShader = NULL;}
		~DomainShaderDX11() { SAFE_RELEASE(m_pShader); }

		AVOID Set() const;

		ABOOL Create(BlobDX11 & shaderbuffer);
		ABOOL CreateAndCompile(AWSTRING fileName, ASTRING entrypoint, BlobDX11 * pErrors = NULL);
	};
}; //Anubis