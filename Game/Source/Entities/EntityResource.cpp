#include "Game_pch.h"
#include "EntityResource.h"

#include "Data\JSONLoader.h"

using namespace Anubis;

AVOID EntityResource::VLoad(const ASTRING & filename)
{
	//parse file
	JSONLoader::Parse(filename);

	//read position data
	m_pos = Vector(JSONLoader::GetAREAL32("position_x"), JSONLoader::GetAREAL32("position_y"), JSONLoader::GetAREAL32("position_z"), 1.0f);
}