#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	class BlobDX11 
	{
	public:
		ID3D10Blob*	m_pBlob;

	public:
		BlobDX11() {}
		~BlobDX11() { SAFE_RELEASE(m_pBlob); }

		ABOOL CompileShader(const AWSTRING & fileName, const ASTRING & entrypoint,
									ShaderType type, BlobDX11 * pErrors) const;
	};

}; //Anubis