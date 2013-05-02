#pragma once
//========================================================================
// Allocator.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	class Allocator
	{
	public:

		template <class T> T* _new()
		{
			return new (allocateAligned(sizeof(T), __alignof(T))) T();
		}

		//template <class T, class P> T* _new(const P & p)
		//{
		//	return new (allocateAligned(sizeof(T), __alignof(T))) T(p);
		//}

		/*** Unaligned memory allocation ***/
		APVOID	allocateUnaligned(AUINT32 bytes);
		AVOID	freeUnaligned(APVOID ptr);

		/*** Aligned memory allocation ***/
		APVOID	allocateAligned(AUINT32 bytes, AUINT32 alignment);
		AVOID	freeAligned(APVOID ptr);
	};
}; //Anubis