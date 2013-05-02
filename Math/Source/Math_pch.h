#pragma once
//========================================================================
// Math_pch.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include <vector>

#include <Anubis.h>

#include "Vectors.h"
#include "Math.h"

using namespace std;

namespace Anubis
{
	/*
	extern Color g_White;
	extern Color g_Black;
	extern Color g_Cyan;
	extern Color g_Red;
	extern Color g_Green;
	extern Color g_Blue;
	extern Color g_Yellow;
	extern Color g_Gray40;
	extern Color g_Gray25;
	extern Color g_Gray65;
	extern Color g_Transparent; */

	extern float3 g_up;
	extern float3 g_right;
	extern float3 g_left;
	extern float3 g_forward;
	extern float3 g_back;
	extern float3 g_camUp;	  //up direction for camera

	extern Vec g_up4;
	extern Vec g_right4;
	extern Vec g_left4;
	extern Vec g_forward4;
	extern Vec g_back4;
	extern Vec g_camUp4;    //up direction for camera

}; //Anubis