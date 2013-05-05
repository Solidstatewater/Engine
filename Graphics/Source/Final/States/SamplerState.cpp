#include "Graphics_pch.h"
#include "SamplerState.h"

using namespace Anubis;

ABOOL SamplerStateParams::Init(D3D11_FILTER filter, D3D11_TEXTURE_ADDRESS_MODE addressU,
				D3D11_TEXTURE_ADDRESS_MODE addressV, D3D11_TEXTURE_ADDRESS_MODE addressW,
				AREAL32 mipLODBias, AUINT32 maxAnisotropy, D3D11_COMPARISON_FUNC comparisonFunc,
				AREAL32* borderColor, AREAL32 minLOD, AREAL32 maxLOD)
{
	Filter = filter;
	AddressU = addressU;
	AddressV = addressV;
	AddressW = addressW;
	MipLODBias = mipLODBias;
	MaxAnisotropy = maxAnisotropy;
	ComparisonFunc = comparisonFunc;

	if (borderColor)
	{
		BorderColor[0] = borderColor[0];
		BorderColor[1] = borderColor[1];
		BorderColor[2] = borderColor[2];
		BorderColor[3] = borderColor[3];
	}

	MinLOD = minLOD;
	MaxLOD = maxLOD;

	return true;
}
