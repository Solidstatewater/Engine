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
	class ShaderResourceViewParamsDX11 : public D3D11_SHADER_RESOURCE_VIEW_DESC
	{
	public:
		ShaderResourceViewParamsDX11() { ZeroMemory(this, sizeof(ShaderResourceViewParamsDX11)); }
		ABOOL InitForTexture2D( AUINT8 format,
								AUINT16 miplevels, 
								AUINT16 mostdetailedmip);
	};

	class ShaderResourceViewDX11
	{
	public:
		ID3D11ShaderResourceView*	m_pView;

	public:
		/*  ==
			Constructor and Destructor
			                          == */
		ShaderResourceViewDX11() {}
		~ShaderResourceViewDX11() { SAFE_RELEASE(m_pView); }

		/*	==
			Create from file
							== */
		ABOOL CreateFromFile(LPCWSTR fileName);
		/* ==
			Bind Shader Resource Views to the pipeline
		== */
		AVOID Set(AUINT16 slot, ShaderType type) const;
	};

	class ShaderResourceViewListDX11
	{
		ID3D11ShaderResourceView**	m_ppViews;
		AUINT8	m_numViews;

	public:
		/*  ==
			Constructor and Destructor
			                          == */
		ShaderResourceViewListDX11(AUINT8 numViews);
		~ShaderResourceViewListDX11();

		/*** Getters ***/
		ID3D11ShaderResourceView** GetView(AUINT8 index) const;

		/* ==
			Bind Shader Resource Views to the pipeline
		== */
		AVOID Set(AUINT16 slot, ShaderType type) const;
	};
}; //Anubis