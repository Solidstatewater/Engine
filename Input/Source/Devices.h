#pragma once
//========================================================================
// Devices.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

// ================= Mouse ================= //
class IMouseHandler
{
public:
	//left mouse button
	AVIRTUAL ABOOL VOnLButtonDown(const CPoint & mousePos)	= 0;
	AVIRTUAL ABOOL VOnLButtonUp(const CPoint & mousePos)	= 0;

	//right mouse button
	AVIRTUAL ABOOL VOnRButtonDown(const CPoint & mousePos)	= 0;
	AVIRTUAL ABOOL VOnRButtonUp(const CPoint & mousePos)	= 0;

	//mouse move
	AVIRTUAL ABOOL VOnMouseMove(const CPoint & mousePos)	= 0;
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