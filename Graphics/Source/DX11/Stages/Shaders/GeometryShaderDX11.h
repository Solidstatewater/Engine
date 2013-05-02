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
	class GeometryShaderDX11
	{
	protected:
		ID3D11GeometryShader*	m_pShader;

	public:
		GeometryShaderDX11() { m_pShader = NULL; }
		~GeometryShaderDX11() { SAFE_RELEASE(m_pShader); }

		AVOID Set() const;

		ABOOL Create(BlobDX11 & shaderbuffer);
		ABOOL VCreateAndCompile(AWSTRING fileName, ASTRING entrypoint, BlobDX11 * pErrors = NULL);
	};
}; //Anubis