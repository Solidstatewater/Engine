#pragma once
//========================================================================
// HashedString.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../Types.h"
#include "../Conventions.h"

namespace Anubis
{
	class HashedString
	{
	public:
		explicit HashedString( ACHAR const * const pString )
			: m_id( hash( pString ) ), m_string( pString )
		{
		}

	AUINT32 GetId() const
	{

		return reinterpret_cast<AUINT32>( m_id );
	}

	const ASTRING & GetString() const
	{
		return m_string;
	}

	ASTATIC APVOID hash( ACHAR const * pString );

	AINLINE ABOOL operator< ( HashedString const & str ) const
	{
		return ( GetId() < str.GetId() );
	}

	AINLINE ABOOL operator== ( HashedString const & str ) const
	{
		return ( GetId() == str.GetId() );
	}

private:

	APVOID             m_id;
	ASTRING		   m_string;
};

}; //Anubis