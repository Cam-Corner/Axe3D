#include "Application.h"


namespace Axe
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		//Set up the window / OpenGL Before doing anything else
		Axe::RenderWindow::Create(1280, 720, Axe::RenderWindow::GetWindowTitle());
		Axe::InputManager::Update();
		Axe::ModelManager::Get();
		srand(time(NULL));

		//Call game start
		Start();

		//Update Loop
		std::cout << "Axe3D STARTED! \n";
		while (Axe::RenderWindow::IsOpen())
		{

			Axe::RenderWindow::Clear();
			Axe::InputManager::Update();
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			if (glfwGetTime() > _CurrentTime)
			{
				std::string TitleName = Axe::RenderWindow::GetWindowTitle() + " " + std::to_string(_FPS);
				glfwSetWindowTitle(Axe::RenderWindow::GetGLFWWindow(), TitleName.c_str());

				_FPS = 0;
				_CurrentTime++;
			}

			_FPS++;

			//Update Override Update
			Update(); // this will update all of the code the dev implemented
			////

			//Draw Everything
			//Axe::ModelManager::DrawStaticMeshes();

			//swap buffer
			Axe::RenderWindow::SwapBuffers();
		}


		//Call Game End
		End();

	}

}