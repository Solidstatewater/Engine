#include "TestGame_pch.h"
#include "TestGame.h"

#include "../../../Math/Source/Geometry/Frustum.h"
#include "Controllers.h"

using namespace Anubis;

ABOOL TestGame::VInitialize()
{
	/*** Initialize player view ***/
	shared_ptr<PlayerView> pView = static_pointer_cast<PlayerView>(VAddGameView(make_shared<PlayerView>(PlayerView())));

	//Add camera
	Frustum & frustum = Frustum();
	//frustum.Init(Pi / 2.0, 1280.0 / 720.0, 0.1, 100.0);
	frustum.Init( 0.4f * 3.14f, 1280.0f / 720.0f, 1.0f, 1000.0f);
	CameraPtr pCamera = make_shared<Camera>(Camera(frustum, Vector(0.0f, 0.0f, -7.0, 1.0f),
		Vector(0.0f, 0.0f, 1.0f, 0.0f),
		Vector(0.0f, 1.0f, 0.0f, 0.0f),
		0.0f, 0.0, 0.0));

	pView->VSetCamera(pCamera);

	//Input controllers
	FreeCameraController* m_pFreeCameraController = new FreeCameraController();
	pView->SetMouseHandler(m_pFreeCameraController);
	pView->SetKeyboardHandler(m_pFreeCameraController);
	pView->SetController(m_pFreeCameraController);

	//call base class initialization
	return Game::VInitialize();
}