#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#define INPUT_LAYOUT D3D11_INPUT_ELEMENT_DESC

namespace Anubis
{
	/*INPUT_LAYOUT InputLayout(	ASTRING SemanticName,
								UINT SemanticIndex,
								DXGI_FORMAT Format,
								UINT InputSlot,
								UINT AlignedByteOffset,
								D3D11_INPUT_CLASSIFICATION InputSlotClass,
  UINT                       InstanceDataStepRate) */

	class InputAssemblerStateDX11
	{
		friend class VertexShaderDX11;

	protected:
		ID3D11InputLayout*			m_pLayout;
		INPUT_LAYOUT*				m_pDesc;
		AUINT8						m_num;
		D3D11_PRIMITIVE_TOPOLOGY	m_topology;

	public:
		InputAssemblerStateDX11() {};
		~InputAssemblerStateDX11() { SAFE_DELETE_ARRAY(m_pDesc); }

		AVOID SetInputLayoutAndTopology() const;
	};
}; //Anubis