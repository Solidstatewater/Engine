#include "Graphics_pch.h"
#include "Algorithms.h"

using namespace Anubis;

AVOID Anubis::CreateNormalTangentBinormal(float3 * positions, float2 * texCoords,
		float3 & normal, float3 & tangent, float3 & binormal)
{
	float3 posVector1, posVector2;
	float2 tuVector, tvVector;
	AREAL r32Den;
	AREAL r32Length;

	//calculate vectors from point to point
	posVector1 = positions[1] - positions[0];
	posVector2 = positions[2] - positions[0];

	//calculate tex coords vectors
	tuVector.x = texCoords[1].x - texCoords[0].x;
	tuVector.y = texCoords[2].x - texCoords[0].x;

	tvVector.x = texCoords[1].y - texCoords[0].y;
	tvVector.y = texCoords[2].y - texCoords[0].y;

	//calculate inverse determinant
	r32Den = 1.0f / (tuVector.x * tvVector.y - tuVector.y * tvVector.x);

	//calculate tangent vector
	tangent.x = (tvVector.y * posVector1.x - tvVector.x * posVector2.x) * r32Den;
	tangent.y = (tvVector.y * posVector1.y - tvVector.x * posVector2.y) * r32Den;
	tangent.z = (tvVector.y * posVector1.z - tvVector.x * posVector2.z) * r32Den;

	r32Length = SqrtR32((tangent.x * tangent.x) + (tangent.y * tangent.y) + (tangent.z * tangent.z));

	tangent.x = tangent.x / r32Length;
	tangent.y = tangent.y / r32Length;
	tangent.z = tangent.z / r32Length;

	//calculate binormal vector
	binormal.x = (tuVector.x * posVector2.x - tuVector.y * posVector1.x) * r32Den;
	binormal.y = (tuVector.x * posVector2.y - tuVector.y * posVector1.y) * r32Den;
	binormal.z = (tuVector.x * posVector2.z - tuVector.y * posVector1.z) * r32Den;

	r32Length = sqrt((binormal.x * binormal.x) + (binormal.y * binormal.y) + (binormal.z * binormal.z));

	binormal.x = binormal.x / r32Length;
	binormal.y = binormal.y / r32Length;
	binormal.z = binormal.z / r32Length;

	//calculate normal vector
	normal.x = (tangent.y * binormal.z) - (tangent.z * binormal.y);
	normal.y = (tangent.z * binormal.x) - (tangent.x * binormal.z);
	normal.z = (tangent.x * binormal.y) - (tangent.y * binormal.x);

	r32Length = sqrt((normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z));

	normal.x = normal.x / r32Length;
	normal.y = normal.y / r32Length;
	normal.z = normal.z / r32Length;
}