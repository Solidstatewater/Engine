#pragma once
//========================================================================
// Renderer_pch.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include <memory>

//STL containers
#include <vector>
#include <list>
#include <d3d11.h>

#include <assert.h>

#include <Anubis.h>

using namespace std;

#define ADX11_API

const AWSTRING	DEFAULT_GBUFFER_SHADER_FILE		= L"GBufferShader.hlsl";
const AWSTRING	DEFAULT_LIGHT_PASS_SHADER_FILE	= L"LightPass.hlsl";

const ASTRING DEFAULT_VERTEX_SHADER_NAME	= "VS";
const ASTRING DEFAULT_HULL_SHADER_NAME		= "HS";
const ASTRING DEFAULT_DOMAIN_SHADER_NAME	= "DS";
const ASTRING DEFAULT_GEOMETRY_SHADER_NAME	= "GS";
const ASTRING DEFAULT_PIXEL_SHADER_NAME		= "PS";
const ASTRING DEFAULT_COMPUTE_SHADER_NAME	= "CS";