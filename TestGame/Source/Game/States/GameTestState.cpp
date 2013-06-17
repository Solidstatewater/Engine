#include "TestGame_pch.h"
#include "GameTestState.h"

#include "../../Entities/BoxEntity/BoxEntityResource.h"
#include "../../Entities/BoxEntity/BoxEntity.h"
#include "../../Entities/BoxEntity/BoxEntityRepresentation.h"

#include "../../Entities/PlaneEntity/PlaneEntity.h"

#include "../../Entities/PointLightEntity/PointLightEntityResource.h"
#include "../../Entities/PointLightEntity/PointLightEntity.h"
#include "../../Entities/PointLightEntity/PointLightEntityRepresentation.h"

using namespace Anubis;

//Initialize game state
AVOID GameTestState::VInitialize( Game * pGame, AUINTPTR uptrData)
{
	m_pScene->VInitialize();

	// **** Generate entities **** //

	//create resource
	BoxEntityResource & box_params = BoxEntityResource();
	box_params.VLoad("Resources\\JSON\\box1_params.json");
	EntityPtr pBox = pGame->VAddEntity(box_params.VCreateEntity(pGame));
	box_params.VCreateRepresentation(m_pScene, pBox);

	//create second box 
	box_params.VLoad("Resources\\JSON\\box2_params.json");
	pBox = pGame->VAddEntity(box_params.VCreateEntity(pGame));
	box_params.VCreateRepresentation(m_pScene, pBox);

	box_params.VLoad("Resources\\JSON\\box3_params.json");
	pBox = pGame->VAddEntity(box_params.VCreateEntity(pGame));
	box_params.VCreateRepresentation(m_pScene, pBox);

	box_params.VLoad("Resources\\JSON\\box4_params.json");
	pBox = pGame->VAddEntity(box_params.VCreateEntity(pGame));
	box_params.VCreateRepresentation(m_pScene, pBox);

	box_params.VLoad("Resources\\JSON\\box5_params.json");
	pBox = pGame->VAddEntity(box_params.VCreateEntity(pGame));
	box_params.VCreateRepresentation(m_pScene, pBox);

	//create back wall
	PlaneEntityResource & plane_params = PlaneEntityResource();
	plane_params.VLoad("Resources\\JSON\\wall1_params.json");
	EntityPtr pPlane =  pGame->VAddEntity(plane_params.VCreateEntity(pGame));
	plane_params.VCreateRepresentation(m_pScene, pPlane);

	//add point light
	PointLightEntityResource & light_params = PointLightEntityResource();
	EntityPtr pLight = pGame->VAddEntity(light_params.VCreateEntity(pGame));
	light_params.VCreateRepresentation(m_pScene, pLight);
}

//Destroy the state
AVOID GameTestState::VRelease( Game * pGame ) 
{
	SAFE_DELETE(m_pScene);
}

//Update the state
AVOID GameTestState::VUpdate( Game * pGame, AREAL64 r64Time, AREAL64 r64ElapsedTime )
{
	m_pScene->VUpdate(r64Time, r64ElapsedTime);
}

//Render State
AVOID GameTestState::VRender( Game * pGame, Renderer * pRenderer, AREAL64 r64Time, AREAL64 r64ElapsedTime )
{
	m_pScene->VRender(pRenderer, r64Time);
}