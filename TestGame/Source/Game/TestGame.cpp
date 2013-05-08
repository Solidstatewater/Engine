#include "TestGame_pch.h"
#include "TestGame.h"

#include"../../../Math/Source/Geometry/Frustum.h"

ABOOL TestGame::VInitialize()
{
	/*** Initialize player view ***/
	shared_ptr<PlayerView> pView = static_pointer_cast<PlayerView>(VAddGameView(make_shared<PlayerView>(PlayerView())));

	//Add camera
	Frustum & frustum = Frustum();
	//frustum.Init(Pi / 2.0, 1280.0 / 720.0, 0.1, 100.0);
	frustum.Init( 0.4f * 3.14f, 1280.0f / 720.0f, 1.0f, 1000.0f);
	CameraPtr pCamera = make_shared<Camera>(Camera(frustum, Vector(-1.0f, 4.0f, -6.0, 1.0f),
		Vector(0.0f, 0.0f, 1.0f, 0.0f),
		Vector(0.0f, 1.0f, 0.0f, 0.0f),
		0.0f, 0.2, 0.0));

	pView->VSetCamera(pCamera);

	//call base class initialization
	return Game::VInitialize();
}