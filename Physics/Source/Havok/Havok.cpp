#include "Physics_pch.h"
#include "Havok.h"

using namespace Anubis;

ABOOL HavokPhysics::VInit() 
{ 
	return true; 
}
		
//Update simulation
AVOID HavokPhysics::VUpdate() 
{
}

HavokPhysics* Anubis::CreateHavokPhysics()
{
	return new HavokPhysics();
}