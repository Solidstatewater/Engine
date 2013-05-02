#pragma once
//========================================================================
// Frustum.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Final/Resources/Textures/Texture1D.h"
#include "Final/Resources/Textures/Texture2D.h"
#include "Final/Resources/Textures/Texture3D.h"
#include "Final/Resources/Views/Views.h"

namespace Anubis
{
	struct GBuffer
	{
		/***
			Initialize buffer
		***/
		AVIRTUAL ABOOL VInitialize() = 0;

		/***
			Bind GBuffer for reading and writing
		***/
		AVIRTUAL AVOID BindForWriting() = 0;
		AVIRTUAL AVOID BindForReading(AUINT16 slot) const = 0;

		/***
			Unbind buffer resources from the pipeline
		***/
		AVIRTUAL VOID UnbindFromWriting() const = 0;
		AVIRTUAL VOID UnbindFromReading(AUINT16 slot) const = 0;
	};

	struct GBufferOne : public GBuffer
	{
		/***
			== Textures
						***/
		Texture2DPtr	m_pPosTex;
		Texture2DPtr	m_pNormalTex;
		Texture2DPtr	m_pDiffuseTex;
		Texture2DPtr	m_pSpecularTex;

		/***
			== ShaderResource View
									***/
		/* ShaderResourceView &	m_pPosSRV;
		ShaderResourceView &	m_pNormalSRV;
		ShaderResourceView &	m_pDiffuseSRV;
		ShaderResourceView &	m_pSpecularSRV; */
		ShaderResourceViewList	m_SRVList;

		/***
			== UnorderedAccess View
									***/
		/*RenderTargetView &	m_pPosRTV;
		RenderTargetView &	m_pNormalRTV;
		RenderTargetView &	m_pDiffuseRTV;
		RenderTargetView &	m_pSpecularRTV; */
		RenderTargetViewList	m_RTVList;

	public:

		/***
			Constructor, Destructor
		***/
		GBufferOne();
		~GBufferOne()	{}

		/***
			Initilize
		***/
		AVIRTUAL ABOOL VInitialize();

		/***
			Bind GBuffer for reading and writing
		***/
		AVIRTUAL AVOID BindForWriting();
		AVIRTUAL AVOID BindForReading(AUINT16 slot) const;

		/***
			Unbind buffer resources from the pipeline
		***/
		AVIRTUAL VOID UnbindFromWriting() const;
		AVIRTUAL VOID UnbindFromReading(AUINT16 slot) const;
	};
};