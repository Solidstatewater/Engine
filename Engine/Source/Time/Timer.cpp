#include "Engine_pch.h"
#include "Timer.h"

using namespace Anubis;

Timer::Timer() : m_i64GameTime(0)
{
	//get amount of cycles per second
	//QueryPerformanceCounter((ALARGE_INT*)&m_u32CountsPerSec); 

	//calculate amount of seconds per cycle
	//m_r64SecondsPerCount = 1.0 / (AREAL64)m_u32CountsPerSec;

	//get CPU frequency 
	AINT64 freq;
	QueryPerformanceFrequency((ALARGE_INT*)&freq);

	//calculate number of ticks in one ms
	m_r32TicksInMs = (AREAL)( (AREAL)freq / 1000.0);

	QueryPerformanceCounter((ALARGE_INT*)&m_i64StartTime);
}

AVOID Timer::Tick()
{
	//Assign current time to previous
	//m_i64PrevTime = m_i64CurrTime;

	//Update current time
	//QueryPerformanceCounter((ALARGE_INT*)&m_i64CurrTime);

	//Calculate time difference
	//AINT64 diff = m_i64CurrTime - m_i64PrevTime;
	//m_r64DeltaTime = diff * m_r64SecondsPerCount;

	//Increment game time
	//m_i64GameTime += diff;

	//if overflow still happened...
	//if (m_r64DeltaTime < 0) m_r64DeltaTime = 0;

	AINT64 i64CurrTime;
	AREAL r32DeltaTime;

	//get current time
	QueryPerformanceCounter((ALARGE_INT*)&i64CurrTime);

	//calculate delta
	r32DeltaTime = (AREAL)(i64CurrTime - m_i64StartTime);

	//convert to milliseconds
	m_r32FrameTime = r32DeltaTime / m_r32TicksInMs;

	//update time of previous frame
	m_i64StartTime = i64CurrTime;

	//sum up total time
	m_i64GameTime += r32DeltaTime;
}