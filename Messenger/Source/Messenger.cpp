#include "Messenger_pch.h"
#include "Messenger.h"

using namespace Anubis;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	Global pointer to the messenger
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
ASTATIC Messenger * g_pMessenger = NULL;

/*** Constructor ***/
Messenger::Messenger()
{
	//assign global pointer to the instance
	g_pMessenger = this;
}

/*** Destructor ***/
Messenger::~Messenger()
{
	//set global pointer to NULL
	if (g_pMessenger)
		g_pMessenger = NULL;
}

/*** Sengleton ***/
Messenger * const Messenger::Get()
{
	return g_pMessenger;
}

// ===================================
//	Private methods for internal stuff
// ===================================

//register message type
ABOOL Messenger::RegisterMessageTypeInternal(MessageType & type)
{
	//Iterate through the register
	auto reg = m_register.begin();

	for (; reg != m_register.end(); reg++)
	{
		//such message type already registered
		if (reg->first == type)
		{
			ASSERT(0 && "Such message type has been already registered!");
			return false;
		}
	}

	//Add new message type to the register
	m_register.push_back(make_pair(type, decltype(reg->second)()));

	return true;
}

//register handler to react to certain message
ABOOL Messenger::RegisterHandlerInternal(MessageHandler const * const pHandler, MessageType & type)
{
	//Iterate though the register
	for (auto reg = m_register.begin(); reg != m_register.end(); reg++)
	{
		//we have found message type to subscribe handler to
		if (reg->first == type)
		{
			//now, iterate through the handlers and make we don't duplicate one
			auto handlers = &reg->second;
			for (auto handler = handlers->begin(); handler != handlers->end(); handler++)
			{
				//this handler has already been registered
				if ((&**handler) == pHandler) //unpack iterator and retrieve pointer from shared_ptr
				{
					ASSERT(0 && "Handler for the message type has already been registered!");
					return false;
				}
			}

			//add new handler to the list for this message type
			handlers->push_back(make_shared<MessageHandler>(*pHandler));

			return true; //handler has been added
		}
	}

	//Such message type is not registered
	return false;
}

//stop caring about certain message
ABOOL Messenger::StopHandlingInternal(MessageHandler const * const pHandler, MessageType & type)
{
	//Iterate though the register
	auto reg = m_register.begin();
	for (; reg != m_register.end(); reg++)
	{
		//we have found message type to unsubscribe handler from
		if (reg->first == type)
		{
			//now, iterate through the handlers
			auto handlers = &reg->second;
			auto handler = handlers->begin();
			for (; handler != handlers->end(); handler++)
			{
				//the registered handler was found
				if ((&**handler) == pHandler) //unpack iterator and retrieve pointer from shared_ptr
					break;
			}

			if (handler != handlers->end())
			{
				//remove handler from the list of this message type
				handlers->erase(handler);
				return true;
			}
			
			//the handler wasn't handling this message type
			ASSERT(0 && "The Handler wasn't handling this message type!");
			return false;
		}
	}

	ASSERT(0 && "Such message tyope is not registered!");
	return true;
}

//delete handler from messenger
ABOOL Messenger::RemoveHandlerInternal(MessageHandler const * const pHandler)
{
	//flag to track whether the handler was registered
	ABOOL registered = false;

	//Iterate though the register
	for (auto reg = m_register.begin(); reg != m_register.end(); reg++)
	{
		//now, iterate through the handlers
		auto handlers = &reg->second;
		auto handler = handlers->begin();
		for (; handler != handlers->end(); handler++)
		{
			//the registered handler was found
			if ((&**handler) == pHandler) //unpack iterator and retrieve pointer from shared_ptr
				break;
		}

		//the handler was subscribed for this message, so delete it
		if (handler != handlers->end())
		{
			handlers->erase(handler);
			registered = true;
		}
	}

	//return false if listener wasn't deleted from anywhere
	return registered;
}

/*
ABOOL Messenger::RemoveHandlerInternal(ACHAR const * const handlerName)
{
	return true;
} */

//send message to the handlers
ABOOL Messenger::SendMessageInternal(Message const & msg)
{
	//Iterate through register and find message we are interested in
	for (auto reg = m_register.begin(); reg != m_register.end(); reg++)
	{
		//message type is found
		if (msg.VGetMessageType() == reg->first)
		{
			//true if message was handled by at least one of the listeners
			ABOOL handled = false;

			//now, iterate through the handlers
			auto handlers = &reg->second;
			for (auto handler = handlers->begin(); handler != handlers->end(); handler++)
			{
				if ((*handler)->VOnEvent(msg))
					handled = true;
			}

			//return false is no listener handled the event
			return handled;
		}
	}

	ASSERT(0 && "Such event type is nor registered!");
	return false;
}

//=================================================
//	Global external methods for using the messenger
//=================================================

//register message type
ABOOL Anubis::RegisterMessageType(MessageType & type)
{
	//assert that we have valid pointer to the messenger
	ASSERT(Messenger::Get());

	//execute internal methods
	return Messenger::Get()->RegisterMessageTypeInternal(type);
}

//register handler to react to certain message
ABOOL Anubis::RegisterHandler(MessageHandler const * const pHandler, MessageType & type)
{
	//assert that we have valid pointer to the messenger
	ASSERT(Messenger::Get());

	//execute internal methods
	return Messenger::Get()->RegisterHandlerInternal(pHandler, type);
}

//stop caring about certain message
ABOOL Anubis::StopHandling(MessageHandler const * const pHandler, MessageType & type)
{
	//assert that we have valid pointer to the messenger
	ASSERT(Messenger::Get());

	//execute internal methods
	return Messenger::Get()->StopHandlingInternal(pHandler, type);
}

//delete handler from messenger
ABOOL Anubis::RemoveHandler(MessageHandler const * const pHandler)
	{
	//assert that we have valid pointer to the messenger
	ASSERT(Messenger::Get());

	//execute internal methods
	return Messenger::Get()->RemoveHandlerInternal(pHandler);
}

/*ABOOL Anubis::RemoveHandler(ACHAR const * const handlerName)
	{
	//assert that we have valid pointer to the messenger
	ASSERT(Messenger::Get());

	//execute internal methods
	return Messenger::Get()->RemoveHandlerInternal(handlerName);
} */

//send message to the handlers
ABOOL Anubis::SendMessage(Message const & msg)
	{
	//assert that we have valid pointer to the messenger
	ASSERT(Messenger::Get());

	//execute internal methods
	return Messenger::Get()->SendMessageInternal(msg);
}
