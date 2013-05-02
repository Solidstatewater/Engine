#pragma once
//========================================================================
// RenderQueue.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Meshes\Meshes.h"

namespace Anubis
{
	class RenderQueue
	{
	private:

		//define list type
		typedef vector<Mesh*> MeshList;

		/* ==============================================
				Queue itself:
					//contains pointers to the meshes
		================================================= */
		MeshList m_queue;

		//********
		//Help variables
		//********
		AUINT32	m_cur;
		AUINT32 m_numMeshes;

	public:
		/**	==========================
			Constructor and Destructor
			==========================	**/
		RenderQueue();
		~RenderQueue() {}

		/**	==========================
					 Methods
			==========================	**/

		//Add new mesh to the queue
		AVIRTUAL AVOID VAdd(Mesh * pMesh);

		//Sort all meshes in effective order
		AVIRTUAL AVOID VSort();

		//get the next mesh to render
		Mesh * Next(); 
	};
};