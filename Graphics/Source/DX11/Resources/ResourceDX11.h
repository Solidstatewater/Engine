#pragma once
//========================================================================
// Graphics.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================
namespace Anubis
{
	class BoxDX11 : public D3D11_BOX
	{
	public:
		BoxDX11() { ZeroMemory(this, sizeof(BoxDX11)); }
		ABOOL Init(AUINT32 left, AUINT32 top, AUINT32 front, AUINT32 right,
			AUINT32 bottom, AUINT32 back);
	};

	class ResourceDX11
	{
	public:
		AVIRTUAL ID3D11Resource* GetResourcePointer() const = 0;
	};
}; //Anubis