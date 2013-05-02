#include "Graphics_pch.h"
#include "ResourceData.h"

using namespace Anubis;

AVOID SubresourceData::SetData(const void* pData, AUINT32 sysMemPitch /* = 0 */, AUINT32 sysMemSlicePitch /* = 0 */)
{
#ifdef ADX11_API
	pSysMem = pData;
	SysMemPitch = sysMemPitch;
	sysMemSlicePitch = sysMemSlicePitch;
#endif
}