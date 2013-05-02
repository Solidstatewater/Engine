#include "Memory_pch.h"
#include "Allocator.h"

using namespace Anubis;

APVOID Allocator::allocateUnaligned(AUINT32 bytes)
{
	return malloc(bytes);
}

AVOID Allocator::freeUnaligned(APVOID ptr)
{
	free(ptr);
}

APVOID Allocator::allocateAligned(AUINT32 bytes, AUINT32 alignment)
{
	ASSERT(alignment > 1 && "Memory alignment should be more then 1 byte!");

	//total number of bytes to allocate
	AUINT32 total_bytes = bytes + alignment;

	//allocate unaligned memory block
	AUINT32 rawAddress = (AUINT32)allocateUnaligned(total_bytes);

	//calculate adjustment
	AUINT32 mask = alignment -1;
	AUINT32 misalignment = (rawAddress & mask);
	AUINT32 adjustment = alignment - misalignment;

	//calculate aligned address
	AUINT32 alignedAddress = rawAddress + adjustment;

	//store adjustment in one byte preceding aligned address
	AUINT8 * pAdjustment = (AUINT8*)(alignedAddress - 1);
	*pAdjustment = adjustment;

	return (APVOID)alignedAddress;
}

AVOID Allocator::freeAligned(APVOID ptr)
{
	//get adjustment
	AUINT32 alignedAddress = (AUINT32)ptr;
	AUINT8* pAdjustment = (AUINT8*)(alignedAddress-1);
	AUINT32 adjustment = (AUINT32)*pAdjustment;

	//calculate raw address
	AUINT32 rawAddress = alignedAddress - adjustment;

	//finally deallocate memory block
	freeUnaligned((APVOID)rawAddress);
}