#include "HashedString.h"

using namespace Anubis;

void * HashedString::hash( char const * pString )
{
	// largest prime smaller than 65536
	AUINT32 BASE = 65521L;

	// NMAX is the largest n such that 255n(n+1)/2 +
	// (n+1)(BASE-1) <= 2^32-1
	AUINT32 NMAX = 5552;

#define DO1(buf,i)  {s1 += tolower(buf[i]); s2 += s1;}
#define DO2(buf,i)  DO1(buf,i); DO1(buf,i+1);
#define DO4(buf,i)  DO2(buf,i); DO2(buf,i+2);
#define DO8(buf,i)  DO4(buf,i); DO4(buf,i+4);
#define DO16(buf)   DO8(buf,0); DO8(buf,8);

    if (pString == NULL)
		return NULL;

    AUINT32 s1 = 0;
    AUINT32 s2 = 0;

	for ( size_t len = strlen( pString ); len > 0 ; )
	{
        AUINT32 k = len < NMAX ? len : NMAX;

		len -= k;

		while (k >= 16)
		{
            DO16(pString);
			pString += 16;
            k -= 16;
        }
		
        if (k != 0) do
		{
			s1 += tolower( *pString++ );
			s2 += s1;
        } while (--k);
		
        s1 %= BASE;
        s2 %= BASE;
    }

#pragma warning(push)
#pragma warning(disable : 4312)

    return reinterpret_cast<void *>( (s2 << 16) | s1 );

#pragma warning(pop)
#undef DO1
#undef DO2
#undef DO4
#undef DO8
#undef DO16
} 