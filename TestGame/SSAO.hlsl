Texture2D   positionTexture :   register( t0 );
Texture2D	normalTexture	:	register( t1 );
Texture2D	depthTexture	:	register( t2 );

cbuffer MatrixBuffer	:	register( c0 )
{
	float4x4 WVP;
};

cbuffer SSAOParams
{
    float noOcclusionThreshold;
    float fullOcclusionThreshold;
}

cbuffer CameraParams
{
    float2 cameraFrustumSize : packoffset(c0);
    float2 cameraParamsPad;
}

cbuffer DepthBufferParams
{
    float2 depthBufferSize;
    float2 depthBufferOffset;
}


////////////////////////////////////////
//shaders input structures
////////////////////////////////////////
struct vs_input
{
	float3 pos		: POSITION;
};

float4 VS( vs_input input ) : SV_POSITION
{
	return mul(float4(input.pos, 1.0f), WVP);
}

float OcclusionFunction(    float fDistance, float fNoOclusionThreshold,
                            float fFullOcclusionThreshold, float fOcclusionThreshold,
                            float fOcclusionPower)
{
    const float fOcclusionEpsilon = 0.01f;
    
    //no occlusion if distance <= 0
    if (fDistance > fOcclusionEpsilon)
    {
        //calculate occlusion range
        float fOcclusionRange = fNoOcclusionThreshold - fFullOcclusionThreshold;
        
        if (fDistance < fFullOcclusionThreshold)
            return 1.0f;
        else
            return max( 1.0f - pow(((fDistance - fFullOcclusionThreshold) / fOcclusionRange,
                                fOcclusionPower)), 0.0f);
    }
    else return 0.0f;
}


float Occlusion(float3 viewPos, float3 SampleDelta,
                float fOcclusionRadius, float fFullOcclusionThreshold,
                float fNoOcclusionThreshold, float fOcclusionPower)
{
    //calculate position of new sample point
    float3 samplePoint = viewPos + fOcclusionRadius * SampleDelta;

    //calculate its UV coords
    float2 samplePointUV = samplePoint.xy / samplePoint.z;
    samplePointUV = samplePointUV / cameraFrustumSize / 0.5f;
    samplePointUV = samplePointUV + float2(-1.0f, -1.0f);
    samplePointUV = samplePointUV * float2(0.5f, 0.5f);
    
    float fSampleDepth = tex2D(depthBuffer, samplePointUV).r;
    float fDistance = samplePoint.z - fSampleDepth;
    return OcclusionFunction (  fDistance, fFullOcclusionThreshold,
                                fNoOcclusionThreshold, fOcclusionPower
                                );
}

float4 PS ( float4 screenPos : SV_POSITION ) : SV_Target
{
    //get view space position and UV coords
	float2 screenUV;
    float3 viewPos = GetViewPos( screenPos, screenUV);
    
    //calculate occlusion
    half fAccumBlock = 0.0f;
    for (int i = 0; i < iSamples; i++)
    {
        float3 SampleDelta = SSAOSamplePoints[i];
        float fBlock = Occlusion(   viewPos,
                                    SampleDelta,
                                    fOcclusionRadius,
                                    fFullOcclusionThreshold,
                                    fNoOcclusionThreshold,
                                    fOcclusionPower );
        fAccumBlock += fBlock;
    }
    fAccumBlock /= iSamples;
    
    return 1.0f - fAccumBlock;
}