#include "RenderWindow.h"
#include <iostream>

namespace axe
{
	RenderWindow::RenderWindow(int fScreenWidth, int fScreenHeight, std::string fWindowName)
	{
		m_ScreenWidth = fScreenWidth;
		m_ScreenHeight = fScreenHeight;

		if (!SetupGLFW(fWindowName))
		{

		}

		if (!SetupGlad())
		{
			glfwTerminate();
		}
	}

	RenderWindow::~RenderWindow()
	{

	}

	bool RenderWindow::IsOpen()
	{
		if (glfwWindowShouldClose(m_Window))
		{
			glfwTerminate();
			return false;
		}

		return true;
	}

	void framebuffer_size_callback(GLFWwindow* fWindow, int fWidth, int fHeight)
	{
		glViewport(0, 0, fWidth, fHeight);

	}

	bool RenderWindow::SetupGLFW(std::string fWindowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		//creating GLFW Window
		m_Window = glfwCreateWindow(m_ScreenWidth, m_ScreenHeight, fWindowName.c_str(), NULL, NULL); //creates the window
		if (m_Window == NULL)//checks to see if the window was able to be created
		{
			std::cout << "RENDER::WINDOW::ERROR: FAILED TO CREATE GLFW WINDOW! \n";
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_Window);

		//glViewport(0, 0, screenWidth, screenHeight);
		glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

		//glEnable(GL_DEPTH_TEST);


		return true;
	}

	bool RenderWindow::SetupGlad()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "RENDER::WINDOW::ERROR: FAILED TO INITIALIZE  GLAD! \n";
			return false;
		}

		return true;
	}

	void RenderWindow::Clear()
	{
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear the screen to a colour
	}

	void RenderWindow::Clear(float fRed, float fGreen, float fBlue, float fAlpha)
	{
		ClampValue(0, 1, fRed);
		ClampValue(0, 1, fGreen);
		ClampValue(0, 1, fBlue);
		ClampValue(0, 1, fAlpha);

		glClearColor(fRed, fGreen, fBlue, fAlpha);// Clear the screen to a colour
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RenderWindow::SwapBuffers()
	{
		//Check and call events and swap buffers
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void RenderWindow::ClampValue(float fMin, float fMax, float& fValue)
	{
		if (fValue < fMin)
		{
			fValue = fMin;
		}

		if (fValue > fMax)
		{
			fValue = fMax;
		}
	}

	void RenderWindow::ClampValue(int fMin, int fMax, int& fValue)
	{
		if (fValue < fMin)
		{
			fValue = fMin;
		}

		if (fValue > fMax)
		{
			fValue = fMax;
		}
	}
}
