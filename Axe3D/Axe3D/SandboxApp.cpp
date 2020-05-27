#include "SandboxApp.h"
#include <istream>

void SandboxApp::Start()
{
	Axe::RenderWindow::SetWindowTitle("Axe 3D");

	Axe::ModelManager::LoadModel("C:/Users/Cameron/Desktop/Dino/TrexByJoel3d.fbx", "TRex");
	Axe::ModelManager::LoadModel("C:/Users/Cameron/Desktop/Plane/Plane.fbx", "Plane");
	//Axe::ModelManager::LoadModel("C:/Users/Cameron/Desktop/investigator-office-colored-version/0.fbx", "Office");
	
	
	_Shader = { std::string("Shaders/VertexShader.txt"), std::string("Shaders/FragmentShader.txt") };

	Axe::RenderWindow::SetActiveCamera(&_MyCamera);
	Axe::RenderWindow::SetWindowResolution(1920, 1080);

	_MyCamera.GetTransform().SetLocation(_CameraPos);
	_MyCamera.GetTransform().SetRotation(_CameraRotation);

	//_Dino = new Axe::StaticMesh();
	_Dino.SetModel(Axe::ModelManager::GetModel("TRex"));
	_Dino.GetTransform().SetLocation(glm::vec3(0, 0, 0));
	_Dino.GetTransform().SetRotation(glm::vec3(0, 0, 0));

	//_Plane = new Axe::StaticMesh();
	_Plane.SetModel(Axe::ModelManager::GetModel("Plane"));
	_Plane.GetTransform().SetLocation(glm::vec3(0, 0, 0));
	_Plane.GetTransform().SetRotation(glm::vec3(-90, 0, 0));
	_Plane.GetTransform().SetScale(glm::vec3(20, 20, 1));

	for (int i = 0; i < 3; i++)
	{
		Axe::Light TempLight;

		TempLight.SetRange(50);

		_Lights.push_back(TempLight);
	}

	//setup Lights

	_Lights[0].SetIntensity(glm::vec3(1, 0, 0));
	_Lights[0].GetTransform().SetLocation(glm::vec3(-10, 1, -10));

	_Lights[1].SetIntensity(glm::vec3(0, 1, 0));
	_Lights[1].GetTransform().SetLocation(glm::vec3(0, 1, 0));

	_Lights[2].SetIntensity(glm::vec3(0, 0, 1));
	_Lights[2].GetTransform().SetLocation(glm::vec3(10, 1, 10));
}

void SandboxApp::Update()
{
	//do stuff		
	CameraMovement(_MyCamera, _CameraPos);


	glm::vec3 AmbientLight(0.6f, 0.6f, 0.6f);

	//draw sprites
	_Shader.UseProgram();
	_Shader.SetVec3("AmbientLightIntensity", AmbientLight);
	_Shader.SetInt("NumberOfLights", _Lights.size());

	if (Axe::InputManager::GetKeyDown(Axe::KeyCode::UP))
	{
		_Lights[0].GetTransform().SetLocation(glm::vec3(_Lights[0].GetTransform().GetLocation().x + 5, 1, _Lights[0].GetTransform().GetLocation().z));
	}

	if (Axe::InputManager::GetKeyDown(Axe::KeyCode::DOWN))
	{
		_Lights[0].GetTransform().SetLocation(glm::vec3(_Lights[0].GetTransform().GetLocation().x - 5, 1, _Lights[0].GetTransform().GetLocation().z));
	}

	if (Axe::InputManager::GetKeyDown(Axe::KeyCode::LEFT))
	{
		_Lights[0].GetTransform().SetLocation(glm::vec3(_Lights[0].GetTransform().GetLocation().x, 1, _Lights[0].GetTransform().GetLocation().z - 5));
	}

	if (Axe::InputManager::GetKeyDown(Axe::KeyCode::RIGHT))
	{
		_Lights[0].GetTransform().SetLocation(glm::vec3(_Lights[0].GetTransform().GetLocation().x, 1, _Lights[0].GetTransform().GetLocation().z + 5));
	}

	for (int i = 0; i < _Lights.size(); i++)
	{
		_Shader.SetVec3("Light[" + std::to_string(i) + "].Intensity", _Lights[i].GetIntensity());
		_Shader.SetVec3("Light[" + std::to_string(i) + "].Position", _Lights[i].GetTransform().GetLocation());
		_Shader.SetFloat("Light[" + std::to_string(i) + "].Range", _Lights[i].GetRange());

	}
	_Dino.Draw(_Shader);
	_Plane.Draw(_Shader);
}

void SandboxApp::End()
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
	fCamera.GetTransform().SetRotation(_CameraRotation);

	float CameraSpeed{ 1.f };

	if (Axe::InputManager::GetKey(Axe::KeyCode::W))
	{
		fCameraPos += fCamera.GetTransform().GetForwardVector() * CameraSpeed;
		fCamera.GetTransform().SetLocation(fCameraPos);
	}

	if (Axe::InputManager::GetKey(Axe::KeyCode::A))
	{
		fCameraPos -= fCamera.GetTransform().GetRightVector() * CameraSpeed;
		fCamera.GetTransform().SetLocation(fCameraPos);
	}

	if (Axe::InputManager::GetKey(Axe::KeyCode::S))
	{
		fCameraPos -= fCamera.GetTransform().GetForwardVector() * CameraSpeed;
		fCamera.GetTransform().SetLocation(fCameraPos);
	}

	if (Axe::InputManager::GetKey(Axe::KeyCode::D))
	{
		fCameraPos += fCamera.GetTransform().GetRightVector() * CameraSpeed;
		fCamera.GetTransform().SetLocation(fCameraPos);
	}
}