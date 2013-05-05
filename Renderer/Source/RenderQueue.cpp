#include "Renderer_pch.h"
#include "RenderQueue.h"

using namespace Anubis;

RenderQueue::RenderQueue() : m_numMeshes(0), m_cur(0)
{
}

AVOID RenderQueue::VAdd(Mesh * pMesh)
{
	//push mesh pointer to the queue
	m_queue.push_back(pMesh);

	//increment counter
	m_numMeshes++;
}

AVOID RenderQueue::VSort()
{
}

Mesh* RenderQueue::Next()
{
	//we just rendered all meshes in the queue
	//if (m_cur == (m_numMeshes - 1))	return NULL;
	if (m_queue.empty())	return NULL;

	//return m_queue[m_cur++];
	Mesh * pMesh = m_queue.back();
	m_queue.pop_back();

	return pMesh;
}