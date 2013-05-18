#pragma once
//========================================================================
// Memory.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	/////////////////////////////////////
	//Macroses
	/////////////////////////////////////
#define START_ALIGNED(name, alignment)	\
	#if defined(COMPILER_INTEL) || defined(COMPILER_MSVC)	\
		_declspec(align(alignment)) name					\
	#elif defined(COMPILER_GNU) || defined(COMPILER_CLANG)	\
		name												\
	#endif									

#define END_ALIGNED(name, alignment)	\
	#if defined(COMPILER_INTEL) || defined(COMPILER_MSVC)	\
	#elif defined(COMPILER_GNU) || defined(COMPILER_CLANG)	\
		__attribute__((aligned(alignment)))					\
	#endif	

	///////////////////////
	/*** new operators ***/
	///////////////////////

}; //Anubis