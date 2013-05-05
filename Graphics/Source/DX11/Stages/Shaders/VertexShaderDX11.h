#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../Fixed/InputAssemblerDX11.h"
#include "../../Other/BlobDX11.h"

namespace Anubis
{
	class VertexShaderDX11
	{
	protected:

		ID3D11VertexShader*	m_pShader;
		InputAssemblerStateDX11*	m_pState;

	public:
		VertexShaderDX11()  { m_pState = new InputAssemblerStateDX11();
							  m_pShader = NULL; }
		~VertexShaderDX11() {	SAFE_RELEASE(m_pShader);
								SAFE_DELETE(m_pState); }

		ABOOL Create(BlobDX11 & shaderbuffer, INPUT_LAYOUT* layout, AUINT8 num,
										 AUINT16 topology);
		ABOOL CreateAndCompile(const AWSTRING& fileName, const ASTRING& entrypoint, INPUT_LAYOUT* layout, AUINT8 num,
			AUINT16 topology, BlobDX11 * pErrors = NULL);

		AVOID Set() const;
	};
}; //Anubis