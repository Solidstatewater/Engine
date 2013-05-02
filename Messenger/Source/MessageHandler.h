#pragma once
//========================================================================
// MessageHandler.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

namespace Anubis
{
	struct Message;
	class MessageHandler
	{
	public:

		//Constructor and Destructor
		MessageHandler()	{}
		~MessageHandler()	{}

		// =======================
		// Get the handler's name
		// =======================
		AVIRTUAL ACHAR const * VGetName() const { return "Default Handler"; }

		/** ==============================
				Method to handle event
			============================== **/
		AVIRTUAL ABOOL VOnEvent(const Message & msg)	{ return true; }
	};
	
	//usefull typedefs
	typedef shared_ptr<MessageHandler> MessageHandlerPtr;

}; //Anubis