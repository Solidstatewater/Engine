#pragma once
//========================================================================
// Algorithms.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../Math/Source/Vectors.h"
#include "../../Math/Source/Math.h"

namespace Anubis
{
	//Calculate normal, tangent and binormal vectors
	AVOID CreateNormalTangentBinormal(float3 * positions, float2 * texCoords,
		float3 & normal, float3 & tangent, float3 & binormal);
}; //Anubis