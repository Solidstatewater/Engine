#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../../Graphics_pch.h"
#include "../../../DX11/Stages/Shaders/VertexShaderDX11.h"
#include "../../../DX11/Stages/Shaders/HullShaderDX11.h"
#include "../../../DX11/Stages/Shaders/DomainShaderDX11.h"
#include "../../../DX11/Stages/Shaders/GeometryShaderDX11.h"
#include "../../../DX11/Stages/Shaders/PixelShaderDX11.h"
#include "../../../DX11/Stages/Shaders/ComputeShaderDX11.h"

namespace Anubis
{
	class VertexShader : public
		#ifdef ADX11_API
			VertexShaderDX11
		#endif
	{
	};
	typedef shared_ptr<VertexShader> VertexShaderPtr;

	class HullShader : public
		#ifdef ADX11_API
			HullShaderDX11
		#endif
	{
	};
	typedef shared_ptr<HullShader> HullShaderPtr;

	class DomainShader : public
		#ifdef ADX11_API
			DomainShaderDX11
		#endif
	{
	};
	typedef shared_ptr<DomainShader> DomainShaderPtr;

	class GeometryShader : public
		#ifdef ADX11_API
			GeometryShaderDX11
		#endif
	{
	};
	typedef shared_ptr<GeometryShader> GeometryShaderPtr;

	class PixelShader : public
		#ifdef ADX11_API
			PixelShaderDX11
		#endif
	{
	};
	typedef shared_ptr<PixelShader> PixelShaderPtr;

	class ComputeShader : public
		#ifdef ADX11_API
			ComputeShaderDX11
		#endif
	{
	};
	typedef shared_ptr<ComputeShader> ComputeShaderPtr;
}; //Anubis