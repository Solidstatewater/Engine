#pragma once

//safe casting. safe of type punning
//#define safe_cast(x, destType) \
//	((union { __typeof(x) a; destType b; }) x.b)
//safe casting. safe of type punning
//#define safe_cast(x, destType) \
//	union safe_union \
//	{ \
//		char a[sizeof(x)]; \
//		destType b; \
//	}; \
//	safe_union my; \
//	my.b;