#include "Game_pch.h"
#include "Entity.h"

using namespace Anubis;

AVOID Entity::VUpdate(AREAL64 r64Time, AREAL64 r64ElapsedTime)
{
	m_pRepresentation->SetCurrentTransform(m_currentWorldMatrix, r64Time);
}