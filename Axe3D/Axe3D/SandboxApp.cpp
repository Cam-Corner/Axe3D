#include "SandboxApp.h"


void SandboxApp::GameStart()
{
	Axe::ModelManager::LoadModel("C:/Users/Cameron/Desktop/Nanosuit/nanosuit.obj", "NanoSuit");
	Axe::ModelManager::LoadModel("C:/Users/Cameron/Desktop/Dino/TrexByJoel3d.fbx", "TRex");
	_Shader = { std::string("Shaders/VertexShader.txt"), std::string("Shaders/FragmentShader.txt") };

	Axe::RenderWindow::SetActiveCamera(&_MyCamera);
	Axe::RenderWindow::SetWindowResolution(1920, 1080);

	_Dino = new Axe::StaticMesh();
	_Dino->SetModel(Axe::ModelManager::GetModel("TRex"));
	_Dino->SetShader(&_Shader);
	_Dino->GetPosition() = glm::vec3(0, 0, 0);
}

void SandboxApp::Update()
{
	//do stuff		
	CameraMovement(_MyCamera, _CameraPos);
}

void SandboxApp::GameEnd()
{

}

void SandboxApp::CameraMovement(Axe::Camera& fCamera, glm::vec3& fCameraPos)
{
	_CameraRotation.y -= Axe::InputManager::GetMouseXOffset() * _Sensitivity;
	_CameraRotation.x += Axe::InputManager::GetMouseYOffset() * _Sensitivity;

	if (_CameraRotation.x > 89)
	{
		_CameraRotation.x = 89;
	}
	else if (_CameraRotation.x < -89)
	{
		_CameraRotation.x = -89;
	}
	fCamera.SetRotation(_CameraRotation);

	float CameraSpeed{ 0.05f };

	if (Axe::InputManager::GetKey(Axe::KeyCode::W))
	{
		fCameraPos += fCamera.GetForwardVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}

	if (Axe::InputManager::GetKey(Axe::KeyCode::A))
	{
		fCameraPos -= fCamera.GetRightVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}

	if (Axe::InputManager::GetKey(Axe::KeyCode::S))
	{
		fCameraPos -= fCamera.GetForwardVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}

	if (Axe::InputManager::GetKey(Axe::KeyCode::D))
	{
		fCameraPos += fCamera.GetRightVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}
}