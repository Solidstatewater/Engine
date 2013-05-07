#include "Renderer_pch.h"
#include "PointLight.h"
#include "../Renderer.h"

using namespace Anubis;

AVOID PointLight::VPreRender(Renderer *pRenderer)
{
	Light::VPreRender(pRenderer);

	//bind point light specific data
	Vec range = Vector(m_r32Range, m_r32Range, m_r32Range, m_r32Range);
	pRenderer->m_pcbPointLight->UpdateSubresource(0, NULL, &range, 0, 0);
	pRenderer->m_pcbPointLight->Set(2, ST_Pixel);
}
