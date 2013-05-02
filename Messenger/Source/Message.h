#pragma once
//========================================================================
// Message.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "../../Definitions/Source/Strings/HashedString.h"

namespace Anubis
{
	//define message type
	typedef HashedString MessageType;

	/** ======================================
			Define Basic Message Structure
		====================================== **/
	struct Message
	{
		//Get Message Type
		AVIRTUAL const MessageType & VGetMessageType() const = 0;
	};

	struct EmptyMessage : public Message
	{
		//Define constructor and destructor which are empty...
		EmptyMessage() {}
		~EmptyMessage() {}
	};

}; //Anubis