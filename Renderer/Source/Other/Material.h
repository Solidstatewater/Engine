#pragma once
//========================================================================
// Material.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Final\Resources\Textures\Texture2D.h"
#include "Final\Resources\Views\Views.h"

namespace Anubis
{
	typedef AUINT32 MaterialId;

	class Material
	{
	protected:

		//unique id
		MaterialId	m_id;

		/*** ======================
				Textures
			 ====================== ***/

		Texture2D * m_pDiffuseTex;
		Texture2D * m_pNormalTex;
		Texture2D * m_pSpecularTex;
		Texture2D * m_pHeightTex;

		/*** =========================
				Shader Resource Views
		     ========================= ***/

		ShaderResourceView * m_pDiffuseSRV;
		ShaderResourceView * m_pNormalSRV;
		ShaderResourceView * m_pSpecularSRV;
		ShaderResourceView * m_pHeightSRV;

		// ===== Specific rendering data ===== //
		
		//remember the slot to which we bound resource view
		AINT32	m_i32DiffuseSlot;
		AINT32	m_i32NormalSlot;
		AINT32	m_i32SpecularSlot;
		AINT32	m_i32HeightSlot;

	public:
		Material();
		~Material();

		AVIRTUAL ABOOL VInitialize(AWSTRING diffuseFileName, AWSTRING normalFileName, AWSTRING specularFileName,
			AWSTRING heightFileName);

		// ===== Bind material to the pipeline ===== //

		AVOID SetDiffuse	(const AUINT16 slot);
		AVOID SetNormal		(const AUINT16 slot);
		AVOID SetSpecular	(const AUINT16 slot);
		AVOID SetHeight		(const AUINT16 slot);

		AVOID Set(const AUINT16 slot); //always bind to the pixel shader

		// ===== Unbind material form the pipeline ===== //

		AVOID UnbindDiffuse	(const AUINT16 slot);
		AVOID UnbindNormal	(const AUINT16 slot);
		AVOID UnbindSpecular(const AUINT16 slot);
		AVOID UnbindHeight	(const AUINT16 slot);

		AVOID Unbind(); //always unbind from the pixel shader
	};
}; //Anubis