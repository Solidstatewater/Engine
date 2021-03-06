#pragma once
//========================================================================
// JSONLoader.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Types.h"
#include "rapidjson\document.h"

namespace Anubis
{
	class JSONLoader
	{
	private:
		//static rapidjson::Document m_doc;
		//static rapidjson::GenericDocument<struct rapidjson::UTF8<char>, class rapidjson::MemoryPoolAllocator<class rapidjson::CrtAllocator> > m_doc;
		//static rapidjson::Value m_array;

	public:
		//Parse document or string with JSON format
		static ABOOL Parse(const ACHAR * const pJSON);
		static ABOOL Parse(const ASTRING & filename);

		//Get field values from JSON
		static ABOOL	GetBool		(const ACHAR * const field);
		static ASTRING	GetString	(const ACHAR * const field);
		static AUINT32	GetAUINT32	(const ACHAR * const field);
		static AUINT64	GetAUINT64	(const ACHAR * const field);
		static AINT32	GetAINT32	(const ACHAR * const field);
		static AINT64	GetAINT64	(const ACHAR * const field);
		static AREAL32	GetAREAL32	(const ACHAR * const field);
		static AREAL64	GetAREAL64	(const ACHAR * const field); 

		/***	Array parsing	***/
		static AVOID	ParseArray	(const ACHAR * const field);

		//Access info about array
		static AUINT32	ArraySize();

		//Access array data
		static ABOOL	GetBoolFromArray	(const AINT32 index);
		static ASTRING	GetStringFromArray	(const AINT32 index);
		static AUINT32	GetAUINT32FromArray	(const AINT32 index);
		static AUINT64	GetAUINT64FromArray	(const AINT32 index);
		static AINT32	GetAINT32FromArray	(const AINT32 index);
		static AINT64	GetAINT64FromArray	(const AINT32 index);
		static AREAL32	GetAREAL32FromArray	(const AINT32 index);
		static AREAL64	GetAREAL64FromArray	(const AINT32 index); 
	};
}; //Anubis