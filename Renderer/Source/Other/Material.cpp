#include "Renderer_pch.h"
#include "Material.h"

#include "Final\General.h"

using namespace Anubis;

Material::Material() :	m_i32DiffuseSlot(-1), m_i32NormalSlot(-1),
						m_i32SpecularSlot(-1), m_i32HeightSlot(-1)
{
	m_pDiffuseSRV	= new ShaderResourceView();
	m_pNormalSRV	= new ShaderResourceView();
	m_pSpecularSRV	= new ShaderResourceView();
	m_pHeightSRV	= new ShaderResourceView();;
}

ABOOL Material::VInitialize(AWSTRING diffuseFileName, AWSTRING normalFileName,
							AWSTRING specularFileName,AWSTRING heightFileName)
{
	if (!m_pDiffuseSRV->CreateFromFile(diffuseFileName.c_str()))
	{
		assert(0 && "Error loading material diffuse texture!");
		return false;
	}

	if (!m_pNormalSRV->CreateFromFile(normalFileName.c_str()))
	{
		assert(0 && "Error loading material normal map!");
		return false;
	}

	if (!m_pSpecularSRV->CreateFromFile(specularFileName.c_str()))
	{
		assert(0 && "Error loading material specular map!");
		return false;
	}

	if (!m_pHeightSRV->CreateFromFile(heightFileName.c_str()))
	{
		assert(0 && "Error loading material height map!");
		return false;
	}

	return true;
}

AVOID Material::SetDiffuse	(AUINT16 slot)
{
	m_pDiffuseSRV->Set(slot, PIXEL_SHADER);
	m_i32DiffuseSlot = slot;
}

AVOID Material::SetNormal	(AUINT16 slot)
{
	m_pNormalSRV->Set(slot, PIXEL_SHADER);
	m_i32NormalSlot = slot;
}

AVOID Material::SetSpecular	(AUINT16 slot)
{
	m_pSpecularSRV->Set(slot, PIXEL_SHADER);
	m_i32SpecularSlot = slot;
}

AVOID Material::SetHeight	(AUINT16 slot)
{
	m_pHeightSRV->Set(slot, PIXEL_SHADER);
	m_i32HeightSlot = slot;
}

AVOID Material::Set(AUINT16 slot)
{
	//don't use methods declared above to avoid 
	//method call overhead

	//bind diffuse
	m_pDiffuseSRV->Set(slot, PIXEL_SHADER);
	m_i32DiffuseSlot = slot++;

	//bind normal
	m_pNormalSRV->Set(slot, PIXEL_SHADER);
	m_i32NormalSlot = slot++;

	//bind specular
	m_pSpecularSRV->Set(slot, PIXEL_SHADER);
	m_i32SpecularSlot = slot++;

	//bind height
	m_pHeightSRV->Set(slot, PIXEL_SHADER);
	m_i32HeightSlot = slot;
}

AVOID Material::UnbindDiffuse	(const AUINT16 slot)
{
	UnbindShaderResourceViews(m_i32DiffuseSlot, 1, PIXEL_SHADER);
	m_i32DiffuseSlot = -1;
}

AVOID Material::UnbindNormal	(const AUINT16 slot)
{
	UnbindShaderResourceViews(m_i32NormalSlot, 1, PIXEL_SHADER);
	m_i32NormalSlot = -1;
}

AVOID Material::UnbindSpecular	(const AUINT16 slot)
{
	UnbindShaderResourceViews(m_i32SpecularSlot, 1, PIXEL_SHADER);
	m_i32SpecularSlot = -1;
}

AVOID Material::UnbindHeight	(const AUINT16 slot)
{
	UnbindShaderResourceViews(m_i32HeightSlot, 1, PIXEL_SHADER);
	m_i32HeightSlot = -1;
}

AVOID Material::Unbind()
{
	UnbindShaderResourceViews(m_i32DiffuseSlot, 4, PIXEL_SHADER);
	m_i32DiffuseSlot = m_i32NormalSlot = m_i32SpecularSlot = m_i32HeightSlot = -1;
}