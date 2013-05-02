#include "Engine_pch.h"
#include "Timer.h"

using namespace Anubis;

Timer::Timer() : m_i64GameTime(0), m_i64PrevTime(0), m_i64CurrTime(0), m_r64DeltaTime(0)
{
	//get amount of cycles per second
	QueryPerformanceCounter((ALARGE_INT*)&m_u32CountsPerSec); 

	//calculate amount of seconds per cycle
	m_r64SecondsPerCount = 1.0 / (AREAL64)m_u32CountsPerSec;
}

AVOID Timer::Tick()
{
	//Assign current time to previous
	m_i64PrevTime = m_i64CurrTime;

	//Update current time
	QueryPerformanceCounter((ALARGE_INT*)&m_i64CurrTime);

	//Calculate time difference
	AINT64 diff = m_i64CurrTime - m_i64PrevTime;
	m_r64DeltaTime = diff * m_r64SecondsPerCount;

	//Increment game time
	m_i64GameTime += diff;

	//if overflow still happened...
	if (m_r64DeltaTime < 0) m_r64DeltaTime = 0;
}