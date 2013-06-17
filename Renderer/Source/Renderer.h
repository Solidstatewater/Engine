#pragma once
//========================================================================
// Renderer.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Cameras\Camera.h"
#include "Final/Resources/Buffers/Buffers.h"
#include "Final/States/SamplerState.h"
#include "Final/States/DepthStencilState.h"
#include "Meshes/Meshes.h"
#include "Lights/Light.h"

namespace Anubis
{
	class Renderer
	{
		friend class Mesh;
		friend class Light;
		friend class PointLight;
	protected:
		/** ================================
				Constant Buffers
			================================
											*/

		//Matrix Buffers
		ConstantBuffer*	m_pcbWorldPlusWVP;
		ConstantBuffer* m_pcbWVP; 

		//Camera Buffers
		ConstantBuffer*	m_pcbCameraPos;
		ConstantBuffer*	m_pcbFrustumSize;

		//Lightning Buffers
		ConstantBuffer*	m_pcbLight;
		ConstantBuffer* m_pcbPointLight;
		ConstantBuffer* m_pcbSpotLight;
		//ConstantBuffer*	m_pcbDirectionalLight;

		//Depth Buffers
		ConstantBuffer*	m_pcbDepthBuffer;

		//SSAO Buffers
		ConstantBuffer*	m_pcbSSAOParams;
		ConstantBuffer*	m_pcbSSAOSamples;

		/** ================================
					Sampler States
			================================
											*/
		SamplerState*	m_pAnisotropySampler16;

		/** ================================
					Depth Stencil States
			================================
											**/
		DepthStencilState*	m_pDepthEnableStencilDisableStandard;
		DepthStencilState*	m_pDepthDisableStencilDisable;
		Texture2D*			m_pDepthTexture;
		ShaderResourceView*	m_pDepthSRV;
		DepthStencilView*	m_pDepthDSV;

		/*** ========================
					Cameras
			 ======================== ***/
		Cameras	m_cameras;

		/*** =========================
			   Rendering Parameteres
		     ========================= ***/
		ABOOL	m_bTexturingOn;
		ABOOL	m_bLightningOn;

	public:

		//constructor
		Renderer();
		~Renderer();

		/***	Initialize	  ***/
		AVIRTUAL ABOOL VInitialize(HWND hWnd, AUINT32 width, AUINT32 height);

		/***	Put something to render	***/
		AVIRTUAL AVOID VPushMesh(Mesh * pMesh) = 0;
		AVIRTUAL AVOID VPushLight(Light * pLight) = 0;

		/***	Add or Remove camera	***/
		AVOID AddCamera(CameraPtr pCamera);
		AVOID RemoveCamera(CameraPtr pCamera);

		/***	Update Render State		***/
		AVIRTUAL AVOID VUpdate(const AUINT32 deltaMilliseconds) = 0;

		/***	Render Scene	***
		**************************/
		AVIRTUAL AVOID VRender() = 0;

		//Accessors
		ABOOL LightningOn() const { return m_bLightningOn; }
		ABOOL TexturingOn() const { return m_bTexturingOn; }

		SamplerState * AnisotropySampler16();
	};

}; //Anubis