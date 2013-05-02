#pragma once

#include <winerror.h>

#define ASSERTIONS_ENABLED 1

#define DebugBrake() __asm { int 3 }

#ifdef ASSERTIONS_ENABLED
	#define ASSERT(expr) \
		if (expr)	\
			{ }		\
		else \
		{ \
			/*reportAssertionFailure(#expr, __FILE__, __LINE__); \
			DebugBrake(); */ \
		} 
#else 
	#define ASSERT(expr)
#endif		 

#ifdef _DEBUG 
	#define Check(x) \
		OutputDebugStringA(x); \
		DebugBrake();
#else
	#define Check(x) \
		OutputDebugStringA(x)
#endif

#ifdef _DEBUG
	#define CheckHR(x) \
		switch (x) \
		{ \
			case S_OK: \
				break; \
			\
			case S_FALSE: \
				OutputDebugStringA("Completed without error, but only partial results were obtained. \
							If a buffer is not large enough to hold the information that is returned \
							to it, the returned information is often truncated to fit into the buffer \
							and S_FALSE is returned from the method."); \
				break; \
			\
			case E_FAIL: \
				OutputDebugStringA("Operation couldn't be performed.");\
				break; \
			\
			case E_INVALIDARG: \
				OutputDebugStringA("One of the arguments passed in was invalid.");\
				break; \
			\
			case E_NOINTERFACE: \
				OutputDebugStringA("The object searched for was not found.");\
				break; \
			\
			case E_OUTOFMEMORY: \
				OutputDebugStringA("A memory allocation attempt failed.");\
				break; \
			\
			case E_UNEXPECTED: \
				OutputDebugStringA("The target was not accessible, ot the engine was not in a state \
							where the function or method could be processed.");\
				break; \
			\
			case E_NOTIMPL: \
				OutputDebugStringA("Not implemented."); \
				break; \
			\
			default: \
				OutputDebugStringA("File not found."); \
				break; \
		};\
		DebugBrake(); 
#else

	#define CheckHR(x) {}

#endif

#define VALID(hr) \
	if (hr == S_OK) \
		return true; \
	else \
	{ \
		CheckHR(hr); \
		return false; \
	};