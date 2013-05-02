#include "Renderer_pch.h"
#include "Meshes.h"

#include "../Renderer.h"
#include "Final\General.h"

using namespace Anubis;

Mesh::Mesh()
{
	m_pVertices = NULL;
	m_pTexCoords = NULL;
	m_pNormals = NULL;

	m_pMaterial = new Material();

	m_pShaders = NULL;
}

Mesh::~Mesh()
{
	SAFE_DELETE(m_pNormals);
	SAFE_DELETE(m_pTexCoords);
	SAFE_DELETE(m_pVertices);
}

AVOID Mesh::VSetMaterial(	AWSTRING diffuseFileName, AWSTRING normalFileName,
							AWSTRING specularFileName,AWSTRING heightFileName)
{
	m_pMaterial->VInitialize(diffuseFileName, normalFileName, specularFileName, heightFileName);
}

//AVOID Mesh::VSetVertexShader	(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetHullShader		(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetDomainShader	(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetGeometryShader	(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetPixelShader		(AWSTRING fileName, ASTRING shaderName);

AVOID Mesh::VPreRender(Renderer *pRenderer)
{
	//set vertex buffer with positions
	m_pVertices->Set(0, 0);

	//set vertex buffer with texture data
	if (pRenderer->TexturingOn())
		m_pTexCoords->Set(1, 0);

	//set vertex buffer with normal data
	if (pRenderer->LightningOn())
		m_pNormals->Set(2, 0);

	//set material
	m_pMaterial->Set(0);

	//set shaders
	m_pShaders->VBind();
}

AVOID Mesh::VRender(Renderer * pRenderer)
{
	Draw(m_pVertices->Count(), 0);
}

AVOID Mesh::VPostRender(Renderer * pRenderer)
{
	m_pMaterial->Unbind();
}