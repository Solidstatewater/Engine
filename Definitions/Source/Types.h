////////////////////////////////////////////////
//Include files
////////////////////////////////////////////////
#include <basetsd.h>
#include <string>
#include <vector>
#include <queue>
#include <list>

//typedef float		R32;
//typedef double		R64;

//typedef __int8		I8;
//typedef __int16		I16;
//typedef __int32		I32;
//typedef __int64		I64;
//typedef __int128	I128;

namespace Anubis
{
////////////////////////////////////////
//floating-point types
#define AREAL		float
#define AREAL32		float
#define	AREAL64		double

////////////////////////////////////////
//integer types
#define	AINT8		__int8
#define	AINT16		__int16
#define	AINT32		__int32
#define	AINT64		__int64

#define	ACHAR		char
#define	AUINT8		unsigned char
#define AUINT16		unsigned short
#define	AUINT32		unsigned int
#define	AUINT64		unsigned __int64

#define ALARGE_INT	LARGE_INTEGER

////////////////////////////////////////
//boolean
#define ABOOL		bool

////////////////////////////////////////
//strings
#define ASTRING		std::string
#define AWSTRING	std::wstring

////////////////////////////////////////
//containers
#define AVECTOR		std::vector
#define ALIST		std::list
#define AQUEUE		std::queue

////////////////////////////////////////
//other types
#define	AVOID		void
#define APVOID		void*
#define	AUINTPTR	UINT_PTR
#define	AINTPTR		INT_PTR
}; //Anubis