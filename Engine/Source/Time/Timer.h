#pragma once
//========================================================================
// Timer.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	class Timer
	{
	private:
		/*** Amount of CPU cycles per second ***/
		//AUINT32	m_u32CountsPerSec;

		/*** Fraction of second per cycle ***/
		//AREAL64 m_r64SecondsPerCount;

		/*** Previous and Current Game Time ***/
		//AINT64	m_i64PrevTime;
		//AINT64  m_i64CurrTime;

		/*** Time passed since game ran ***/
		//AINT64	m_i64GameTime;

		/*** Times passed ***/
		//AREAL64 m_r64DeltaTime;

		//Time of the last frame (in ticks)
		AINT64 m_i64StartTime;

		//Number of CPU ticks in millisecond
		AREAL m_r32TicksInMs;

		//Time taken for frame(in ms)
		AREAL m_r32FrameTime;

		//Time passed since game started
		AINT64	m_i64GameTime;

	public:

		/*** Constructor ***
			 Destructor
		***				 ***/
		Timer();
		~Timer() {}

		//Tick
		AVOID Tick();

		/***
			//Getters
						***/
		//AINT64	GetGameTime()  const { return m_i64GameTime; }
		//AREAL64 GetGameTimeSeconds() const { return m_i64GameTime * m_r64SecondsPerCount; }
		//AREAL64 GetDeltaTime() const { return m_r64DeltaTime; }
		//AINT64	GetCurrentTime() const { return m_i64CurrTime; }
		//AREAL64 GetCurrentTimeSeconds() const { return m_i64CurrTime * m_r64SecondsPerCount; }

		AREAL GetGameTime() const			{ return m_i64GameTime / m_r32TicksInMs; }
		AREAL GetGameTimeSeconds() const	{ return m_i64GameTime / m_r32TicksInMs / 1000.0; }
		AREAL GetDeltaTime() const			{ return m_r32FrameTime;}
		AREAL GetDeltaTimeSeconds() const	{ return m_r32FrameTime / 1000.0; }
	};
}; //Anubis