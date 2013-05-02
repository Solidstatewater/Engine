#pragma once
//========================================================================
// QuadObject.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	class QuadTreeNode;

	/* ======================================
		Every object which is wanted to be
		inserted to the tree should derive this class
		///////////////////////
	=====================================*/
	class QuadTreeObject
	{
	public:
		/* Constructor and destructor */
		QuadTreeObject()	{}
		~QuadTreeObject()	{}

		/* ************************************
					methods
		************************************* */
		AVIRTUAL const aabb & GetAabb() const = 0;

		/* ====================================
					mutators
		====================================== */

		//set node, where the object was inserted
		AVOID SetNode(const QuadTreeNode * const pNode) { m_pNode = pNode; }

		/* ====================================
					getters
		====================================== */

		//return tree node, where the object was inserted
		AINLINE const QuadTreeNode * GetNode() const { return m_pNode; }

	protected:

		/* Tree Node where this object was inserted */
		QuadTreeNode*	m_pNode;
	};
}; //Anubis