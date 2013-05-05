#include "Renderer_pch.h"
#include "Meshes.h"

#include "../Renderer.h"
#include "Final\General.h"

using namespace Anubis;

Mesh::Mesh()
{
	m_objectTransform = Mat4x4::Identity();
	m_worldTransform = Mat4x4::Identity();

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

AVOID Mesh::SetWorldTransform(const Mat4x4 & transform)
{
	m_worldTransform = m_objectTransform * transform;
}

//AVOID Mesh::VSetVertexShader	(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetHullShader		(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetDomainShader	(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetGeometryShader	(AWSTRING fileName, ASTRING shaderName);
//AVOID Mesh::VSetPixelShader		(AWSTRING fileName, ASTRING shaderName);

AVOID Mesh::VPreRender(Renderer *pRenderer, const Mat4x4 & viewprojection)
{
	//update constant buffers
	struct MatrixBuffer
	{
		Mat4x4 m_world;
		Mat4x4 m_WVP;
	};
	MatrixBuffer buffer;
	buffer.m_world = m_worldTransform;
	buffer.m_WVP = m_worldTransform * viewprojection;
	buffer.m_world.Transpose();
	buffer.m_WVP.Transpose();
	pRenderer->m_pcbWorldPlusWVP->UpdateSubresource(0, NULL, &buffer, 0, 0);
	pRenderer->m_pcbWorldPlusWVP->Set(0, ST_Vertex);

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