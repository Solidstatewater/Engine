#include "Scene_pch.h"
#include "Root.h"

using namespace Anubis;

//constructor
RootRepresentation::RootRepresentation() : EntityRepresentation(0)
{
}

//Add and remove children
AVOID RootRepresentation::VAddChild(EntityRepresentation* pRepr, RenderPass pass,
									EntityRepresentationId parentId)
{
	//if no parent for this representation than just 
	//add it to the right pass
	if (!parentId)
		m_passes[pass].push_back(pRepr);
	else
	{
		if (EntityRepresentation * pParent = FindChild(parentId, pass))
		{
			pParent->VAddChild(pRepr);
		}
		else
		{
			assert(0 && "Parent with such Id doesn't exists or lies in the other pass!");
		}
	}
}
AVOID RootRepresentation::VRemoveChild(EntityRepresentationId id)
{
}

EntityRepresentation* RootRepresentation::VFindChild(EntityRepresentationId id)
{
	for (int pass = 0; pass < NUM_RENDER_PASSES; pass++)
	{
		if (EntityRepresentation* pResult = FindChild(id, (RenderPass)pass))
		{
			return pResult;
		}
	}

	//not found
	return NULL;
}

EntityRepresentation* RootRepresentation::FindChild(EntityRepresentationId id, RenderPass pass)
{
	//check out all children
	for (EntityRepresentation* pRepr : m_passes[pass])
	{
		if (EntityRepresentation* pResult = pRepr->VFindChild(id))
		{
			return pResult;
		}
	}

	//not found
	return NULL;
}

//put all low-level mesh data to the renderer
AVOID RootRepresentation::VRender(Scene* pScene, Renderer * pRenderer, AREAL64 r64CurrentTime)
{
	VPushParameters(pScene, r64CurrentTime);
	VSendRenderingData(pRenderer);

	//render all passes
	for (int i  = 0; i < NUM_RENDER_PASSES; i++)
	{
		//render all representations from the given pass
		for (EntityRepresentation* pRepr : m_passes[i])
		{
			pRepr->VRender(pScene, pRenderer, r64CurrentTime);
		}
	}

	VPullParameters(pScene);
}