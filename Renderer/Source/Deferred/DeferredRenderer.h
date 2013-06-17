#pragma once
//========================================================================
// DeferredRenderer.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../Renderer.h"
#include "GBuffer.h"

#include "../Cameras/Camera.h"
#include "../RenderQueue.h"

#include "../Lights/DirectionalLight.h"
#include "../Lights/PointLight.h"
#include "../Lights/SpotLight.h"

#include "Final\Resources\Textures\Texture2D.h"
#include "Final\Resources\Views\Views.h"

namespace Anubis
{
	class DeferredRenderer : public Renderer
	{
	protected:
		// ======================= //
		//	All Rendering Data === //
		// ======================= //
		GBufferOne	m_gbuffer;

		ConstantBuffer*	m_pMatrixBuffer;

		//meshes
		RenderQueue m_queue;

		//lights
		typedef vector<Light*> LightList;
		LightList	m_lights;

		//data for light rendering
		VertexBuffer*	m_pVertices;
		VertexBuffer*	m_pTexCoords;
		INPUT_LAYOUT*	m_pLayout;

		//===============================
		//Ambient occlusion
		INPUT_LAYOUT*	m_pSSAOLayout;
		ShaderBunch*	m_pSSAOShaders;
		Texture2D*		m_pSSAOTexture;
		ShaderResourceView*	m_pSSAOSRV;
		RenderTargetView*	m_pSSAORTV;

	public:
		/***		=====		***
		 Constructor and Destructor
		 ***		=====	   ***/
		DeferredRenderer();
		~DeferredRenderer();

		/***	Initialize	  ***/
		ABOOL VInitialize(HWND hWnd, AUINT32 width, AUINT32 height);

		/***	Put something to render	***/
		AVOID VPushMesh(Mesh * pMesh);
		AVOID VPushLight(Light * pLight);

		/***	Light Rendering ***/
		AVOID PrepareForLightPass(CameraPtr pCamera);
		AVOID CalculateAmbientOcclusion(CameraPtr pCamera);

		/***	Update Render State		***/
		AVOID VUpdate(const AUINT32 deltaMilliseconds);

		/***	Render Scene	***
		**************************/
		AVOID VRender();
		AVOID VSetStateForGBuffer();
		AVOID VsetStateForFinalPass();
	};
}; //Anubis