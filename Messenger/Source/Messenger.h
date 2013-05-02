#pragma once
//========================================================================
// Messenger.h
//
// This code is part of Minotower Games Engine 1.0v
//
// (c) Copyright 2012 Muralev Evgeny
//========================================================================

#include "Message.h"
#include "MessageHandler.h"

using namespace std;

namespace Anubis
{
	class Messenger
	{
	public:
		//Constructor and Destructor
		explicit Messenger();
		~Messenger();

		/** ============= **/
		//	  Singleton	   //
		/** ============= **/
		ASTATIC Messenger * const Get();

	private:

		//Usefull typedefs
		typedef vector<MessageHandlerPtr>			Handlers;					//list of handlers
		typedef pair<MessageType &, Handlers>		MessageTypeAndHandlersPair; //element in handlers map
		typedef list<MessageTypeAndHandlersPair>	HandlersMap;				//maps message type to handlers

		/*****
			Declare Messenger lists
								 *****/
		HandlersMap	m_register;

		/** ============================================ **/
		//		Private methods for internal stuff		  //
		/**	============================================ **/

		//register message type
		ABOOL RegisterMessageTypeInternal(MessageType & type);

		//register handler to react to certain message
		ABOOL RegisterHandlerInternal(MessageHandler const * const pHandler,
			MessageType & type);

		//stop caring about certain message
		ABOOL StopHandlingInternal(MessageHandler const * const pHandler, MessageType & type);

		//delete handler from messenger
		ABOOL RemoveHandlerInternal(MessageHandler const * const pHandler);
		//ABOOL RemoveHandlerInternal(ACHAR const * const handlerName);

		//send message to the handlers
		ABOOL SendMessageInternal(Message const & msg);

	private:

		/** =========================================== **/
		//		Global methods for message-handling		 //
		//												 //
		//	 These are external methods (basically -	 //
		//   wrappers arounnd !Internal! methods) and	 //
		//	 make needed assertions to safely use them   //
		//	 throught the code.							 //
		//												 //	
		/**	=========================================== **/

		//register message type
		friend ABOOL RegisterMessageType(MessageType & type);

		//register handler to react to certain message
		friend ABOOL RegisterHandler(MessageHandler const * const pHandler,
			MessageType & type);

		//stop caring about certain message
		friend ABOOL StopHandling(MessageHandler const * const pHandler, MessageType & type);

		//delete handler from messenger
		friend ABOOL RemoveHandler(MessageHandler const * const pHandler);
		//friend ABOOL RemoveHandler(ACHAR const * const handlerName);

		//send message to the handlers
		friend ABOOL SendMessage(Message const & msg);
	};

}; //Anubis