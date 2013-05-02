#pragma once

#include <Windows.h>
#include <assert.h>
#include <memory>
#include <D3DX11.h>

//containers
#include <list>
#include <vector>

#include <Anubis.h>

using namespace std;

#define ADX11_API

/****************************************
==
==	Timing
==
****************************************/
const AREAL64 r64TimeStep = 33.3;

/****************************************
==
==	Application Entry Point
==
****************************************/
#ifdef WIN32
extern AINT32 WINAPI GameMain(HINSTANCE hInstance,
							  HINSTANCE hPrevInstance,
							  LPWSTR	lpCmdLine,
							  AINT32	nCmdShow);
#endif //WIN32