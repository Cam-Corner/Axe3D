#pragma once
#include "AxeAPI.h"

class SandboxApp : public Axe::Application
{
public:
	SandboxApp() {}
	~SandboxApp() {}

private:
	virtual void GameStart() override;
	virtual void Update() override;
	virtual void GameEnd() override;

	void CameraMovement(Axe::Camera& fCamera, glm::vec3& fCameraPos);

private:
	Axe::Shader _Shader;
	glm::vec3 _CameraPos{ 0, 0, 0 };
	Axe::Camera _MyCamera;


	double _LastXVal, _LastYVal;
	glm::vec3 _CameraRotation{ 0, -90, 0 };
	float _Sensitivity = 0.1f;

	Axe::StaticMesh* _Dino;
	bool _Fullscreen = false;
};

Axe::Application* Axe::CreateApplication()
{
	return new SandboxApp();
}

