#include "Renderer_pch.h"
#include "PointLight.h"

using namespace Anubis;

AVOID PointLight::VPreRender()
{
	Light::VPreRender();

	//bind constant buffer to the pipeline
	//m_pBuffer->UpdateSubresource(0, NULL, m_pData, 0, 0);
	//m_pBuffer->Set(0, ST_Pixel);
}
