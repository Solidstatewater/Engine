//==================================================//
//Includes
//==================================================//
#include <Windows.h>

#pragma once

/////////////////////////////////////////////////////
//Bitwise macroses
/////////////////////////////////////////////////////
#define Bit_Left(x) (1 << x)

/////////////////////////////////////////////////////
//Memory management
/////////////////////////////////////////////////////
#if !defined(SAFE_DELETE)
	#define SAFE_DELETE(x) if(x) delete x; x=NULL;
#endif

#if !defined(SAFE_DELETE_ARRAY)
	#define SAFE_DELETE_ARRAY(x) if (x) delete [] x; x=NULL; 
#endif

#if !defined(SAFE_RELEASE)
	#define SAFE_RELEASE(x) if(x) x->Release(); x=NULL;
#endif

#define ALIGN16 _declspec(align(16))

/////////////////////////////////////////////////////
//Other defines
/////////////////////////////////////////////////////
#if !defined INFINITE
	#define INFINITE = 0xffffffff;
#endif

#define PI		 = 3.14159265;

#define fOPAQUE (1.0f)
#define iOPAQUE (1)
#define fTRANSPARENT (0.0f)
#define iTRANSPARENT (0)

#define MEGABYTE (1024 * 1024)
#define SIXTY_HERTZ (16.66f)

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
