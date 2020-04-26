#include <iostream>
#include "RenderWindow.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "stb_image.h"
#include <time.h>
#include "Model.h"
#include "InputManager.h"

//function for camera movement
void CameraMovement(axe::Camera& fCamera, glm::vec3& fCameraPos);

int main()
{
	axe::RenderWindow::Create(1280, 720, "Axe 3D | FPS: 0");
	axe::InputManager::Update();

	srand(time(NULL));
	//axe::RenderWindow Window(1920, 1080, "Axe 3D | FPS: 0");
	axe::Shader MyShader{ std::string("Shaders/VertexShader.txt"), std::string("Shaders/FragmentShader.txt") };
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	bool Pressed = false;
	glm::vec3 CameraPos{ 0, 0, 0 };
	axe::Camera MyCamera;

	int FPS{ 0 };
	float CurrentTime{ 1 };
	std::string* NanoPath = new std::string("C:/Users/Cameron/Desktop/Nanosuit/nanosuit.obj");
	std::string* RexPath = new std::string("C:/Users/Cameron/Desktop/Dino/TrexByJoel3d.fbx");
	axe::Model Nano_Model(NanoPath);
	axe::Model Rex_Model;
	Rex_Model.Load(RexPath);


	std::cout << "STARTED! \n";
	while (axe::RenderWindow::IsOpen())
	{
		//clear the screen
		//Window.Clear(0.0f, 0.0f, 1.0f, 1.0f);
		axe::RenderWindow::Clear();
		axe::RenderWindow::UpdateInput();
		axe::InputManager::Update();

		if (glfwGetTime() > CurrentTime)
		{
			std::string TitleName = "Axe 3D   |    FPS: " + std::to_string(FPS);
			glfwSetWindowTitle(axe::RenderWindow::GetGLFWWindow(), TitleName.c_str());
			
			FPS = 0;
			CurrentTime++;
		}
		
		FPS++;

		//do stuff		
		CameraMovement(MyCamera, CameraPos);

		MyShader.UseProgram();
		
		float ScreenWidth = axe::RenderWindow::GetScreenResolution().x;
		float ScreenHeight = axe::RenderWindow::GetScreenResolution().y;
		glm::mat4 Projection = glm::perspective(glm::radians(70.0f), ScreenWidth / ScreenHeight , 0.1f, 10000.0f);
		MyShader.SetMat4("Projection", Projection);

		glm::mat4 View = MyCamera.GetViewMatrix();
		View = glm::translate(View, glm::vec3(0.0f, 0.0f, 0.0f));
		MyShader.SetMat4("View", View);

		glm::mat4 Model = glm::mat4(1.0f);
		//Model = glm::rotate(Model, , glm::vec3(1.0f, 1.0f, 0.0f));
		Model = glm::translate(Model, glm::vec3(-5.0f, 0, 0));
		MyShader.SetMat4("Model", Model);
		Nano_Model.Draw(MyShader);

		Model = glm::translate(Model, glm::vec3(5.0f, 0, 0));
		MyShader.SetMat4("Model", Model);
		Rex_Model.Draw(MyShader);

		//swap buffer
		axe::RenderWindow::SwapBuffers();
	}

	return 0;
}

double LastXVal, LastYVal;
glm::vec3 CameraRotation{ 0, -90, 0 };
float Sensitivity = 0.1f;

void CameraMovement(axe::Camera& fCamera, glm::vec3& fCameraPos)
{
	CameraRotation.y -= axe::RenderWindow::GetMouseXOffset() * Sensitivity;
	CameraRotation.x += axe::RenderWindow::GetMouseYOffset() * Sensitivity;

	if (CameraRotation.x > 89)
	{
		CameraRotation.x = 89;
	}
	else if (CameraRotation.x < -89)
	{
		CameraRotation.x = -89;
	}
	fCamera.SetRotation(CameraRotation);

	float CameraSpeed{ 0.05f };

	if (axe::InputManager::GetKey(axe::KeyCode::W))
	{
		fCameraPos += fCamera.GetForwardVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}

	if (axe::InputManager::GetKey(axe::KeyCode::A))
	{
		fCameraPos -= fCamera.GetRightVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}

	if (axe::InputManager::GetKey(axe::KeyCode::S))
	{
		fCameraPos -= fCamera.GetForwardVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}

	if (axe::InputManager::GetKey(axe::KeyCode::D))
	{
		fCameraPos += fCamera.GetRightVector() * CameraSpeed;
		fCamera.SetPosition(fCameraPos);
	}
}