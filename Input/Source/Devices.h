#pragma once
//========================================================================
// Devices.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Defines.h"
#include "../../Math/Source/Math.h"

// ================= Mouse ================= //
class IMouseHandler
{
public:
	//left mouse button
	AVIRTUAL ABOOL VOnLButtonDown(const AREAL & x, const AREAL & y)	= 0;
	AVIRTUAL ABOOL VOnLButtonUp(const AREAL & x, const AREAL & y)	= 0;

	//right mouse button
	AVIRTUAL ABOOL VOnRButtonDown(const AREAL & x, const AREAL & y)	= 0;
	AVIRTUAL ABOOL VOnRButtonUp(const AREAL & x, const AREAL & y)	= 0;

	//mouse move
	AVIRTUAL ABOOL VOnMouseMove(const AREAL & x, const AREAL & y)	= 0;
};

// ================= Keyboard ================= //

//store pressed key
typedef AUINT8 Key;

class IKeyboardHandler
{
public:
	AVIRTUAL ABOOL VOnKeyDown(Key const key)	= 0;
	AVIRTUAL ABOOL VOnKeyUp(Key const key)		= 0;
};

// ================= Joystick ================= //