#pragma once
//========================================================================
// Scene_pch.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include <D3D11.h>
#include <D3DX11.h>

#include <memory>
#include <assert.h>

//STL containers
#include <vector>
#include <list>

#include <Anubis.h>
#include <Defines.h>
#include "Allocator.h"

using namespace std;

#define ADX11_API

enum Color
{
	red,
	green,
	blue,
	yellow,
	black,
	white,
	purple,
};

namespace Anubis
{
	extern Allocator * g_pSceneAllocator = NULL;
}