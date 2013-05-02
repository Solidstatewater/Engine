#pragma once
//========================================================================
// Meshes.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Final/Resources/Buffers/Buffers.h"
#include "../Other/Material.h"
#include "../Other/ShaderBunch.h"

namespace Anubis
{
	class Renderer;
	class Mesh
	{
	protected:
		//Vertex buffers
		VertexBuffer*	m_pVertices;
		VertexBuffer*	m_pTexCoords;
		VertexBuffer*	m_pNormals;

		Material*		m_pMaterial;

		ShaderBunch*	m_pShaders;

	public:
		//Constructor and destructor
		Mesh();
		~Mesh();

		/**	Initialization **/
		//AVIRTUAL ABOOL VInitialize(ASTRING fileName) = 0;
		AVIRTUAL AVOID VSetMaterial(AWSTRING diffuseFileName, AWSTRING normalFileName,
									AWSTRING specularFileName,AWSTRING heightFileName);

		//Shaders
		//AVIRTUAL AVOID VSetVertexShader		(AWSTRING fileName, ASTRING shaderName);
		//AVIRTUAL AVOID VSetHullShader		(AWSTRING fileName, ASTRING shaderName);
		//AVIRTUAL AVOID VSetDomainShader		(AWSTRING fileName, ASTRING shaderName);
		//AVIRTUAL AVOID VSetGeometryShader	(AWSTRING fileName, ASTRING shaderName);
		//AVIRTUAL AVOID VSetPixelShader		(AWSTRING fileName, ASTRING shaderName);

		/** Rendering methods **/
		AVIRTUAL AVOID VPreRender(Renderer *pRenderer);		//change pipeline state if needed
		AVIRTUAL AVOID VRender(Renderer * pRenderer);		//render the mesh
		AVIRTUAL AVOID VPostRender(Renderer * pRenderer);			//restore previous pipeline state if needed
	};

	//useful typedefs
	typedef shared_ptr<Mesh> MeshPtr;
	typedef vector<MeshPtr> Meshes;

	/*class IndexedMesh : public Mesh
	{
		IndexBuffer*	m_pIndexBuffer;
	};

	// ====================================== //
	//		Mesh containing normals data	  //
	// ====================================== //
	class UnlitMesh : public IndexedMesh
	{
	protected:
		VertexBuffer*	m_pNormals;
	};

	// ===================================== //
	// Textured Mesh containing normals data //
	// ===================================== //
	class TexturedUnlitMesh : public UnlitMesh
	{
	}; */
}; //Anubis