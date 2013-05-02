#include "Graphics_pch.h"
#include "../../../Final/General.h"
#include "InputAssemblerDX11.h"

using namespace Anubis;

AVOID InputAssemblerStateDX11::SetInputLayoutAndTopology() const
{
	D3D11DeviceContext()->IASetInputLayout(m_pLayout);
	D3D11DeviceContext()->IASetPrimitiveTopology(m_topology);
}