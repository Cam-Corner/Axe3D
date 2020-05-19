#include "RenderWindow.h"
#include <iostream>

namespace Axe
{
	bool RenderWindow::CreateImp(int ScreenWidth, int ScreenHeight, std::string WindowName)
	{
		if (!_HasWindow)
		{
			_ScreenWidth = ScreenWidth;
			_ScreenHeight = ScreenHeight;

			if (!SetupGLFW(WindowName))
			{

			}

			if (!SetupGlad())
			{
				glfwTerminate();
			}

			_HasWindow = true;
			return true;
		}

		return false;
	}

	RenderWindow::~RenderWindow()
	{

	}

	bool RenderWindow::IsOpenImp()
	{
		if (glfwWindowShouldClose(_Window))
		{
			glfwTerminate();
			return false;
		}

		return true;
	}

	void framebuffer_size_callback(GLFWwindow* Window, int Width, int Height)
	{
		glViewport(0, 0, Width, Height);

	}


	bool RenderWindow::SetupGLFW(std::string WindowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		//creating GLFW Window
		_Window = glfwCreateWindow(_ScreenWidth, _ScreenHeight, WindowName.c_str(), NULL, NULL); //creates the window
		if (_Window == NULL)//checks to see if the window was able to be created
		{
			std::cout << "RENDER::WINDOW::ERROR: FAILED TO CREATE GLFW WINDOW! \n";
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(_Window);

		//glViewport(0, 0, screenWidth, screenHeight);
		glfwSetFramebufferSizeCallback(_Window, framebuffer_size_callback);;

		return true;
	}

	bool RenderWindow::SetupGlad()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "RENDER::WINDOW::ERROR: FAILED TO INITIALIZE  GLAD! \n";
			return false;
		}
		
		SetOpenGLSettings();
		return true;
	}

	void RenderWindow::SetOpenGLSettings()
	{
		glEnable(GL_DEPTH_TEST);
		//glDepthMask(GL_FALSE);
		glDepthFunc(GL_LESS);
		
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		
		glEnable(GL_STENCIL_TEST);

	}

	void RenderWindow::ClearImp()
	{
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);// Clear the screen to a colour
	}

	void RenderWindow::ClearImp(float Red, float Green, float Blue, float Alpha)
	{
		ClampValue(0, 1, Red);
		ClampValue(0, 1, Green);
		ClampValue(0, 1, Blue);
		ClampValue(0, 1, Alpha);

		glClearColor(Red, Green, Blue, Alpha);// Clear the screen to a colour
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RenderWindow::SwapBuffersImp()
	{
		//Check and call events and swap buffers
		glfwSwapBuffers(_Window);
		glfwPollEvents();
		
	}

	void RenderWindow::ClampValue(float Min, float Max, float& Value)
	{
		if (Value < Min)
		{
			Value = Min;
		}

		if (Value > Max)
		{
			Value = Max;
		}
	}

	void RenderWindow::ClampValue(int Min, int Max, int& Value)
	{
		if (Value < Min)
		{
			Value = Min;
		}

		if (Value > Max)
		{
			Value = Max;
		}
	}

	void RenderWindow::SetWindowResolutionImp(unsigned int Width, unsigned int Height)
	{
		_ScreenWidth = Width;
		_ScreenHeight = Height;
		glfwSetWindowSize(_Window, _ScreenWidth, _ScreenHeight);
	}

	void RenderWindow::SetFullScreenImp(bool Value)
	{
		if (Value)
		{
			glfwSetWindowMonitor(_Window, glfwGetPrimaryMonitor(), 0, 0, _ScreenWidth, _ScreenHeight, GLFWvidmode().refreshRate);
		}
		else
		{
			glfwSetWindowMonitor(_Window, 0, 0, 0, _ScreenWidth, _ScreenHeight, GLFWvidmode().refreshRate);
		}
	}
}
