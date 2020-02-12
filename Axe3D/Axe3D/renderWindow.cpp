#include "renderWindow.h"
#include <iostream>

namespace axe
{
	renderWindow::renderWindow(int fScreenWidth, int fScreenHeight, std::string fWindowName)
	{
		screenWidth = fScreenWidth;
		screenHeight = fScreenHeight;
		
		if (setupGLFW(fWindowName))
		{

		}
	}

	renderWindow::~renderWindow()
	{

	}

	void framebuffer_size_callback(GLFWwindow* fWindow, int fWidth, int fHeight)
	{
		glViewport(0, 0, fWidth, fHeight);
	}

	bool renderWindow::setupGLFW(std::string fWindowName) 
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	
		//creating GLFW Window
		window = glfwCreateWindow(screenWidth, screenHeight, fWindowName.c_str(), NULL, NULL); //creates the window
		if (window == NULL)//checks to see if the window was able to be created
		{
			std::cout << "ERROR: Failed to create GLFW window! /n";
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(window);

		glViewport(0, 0, screenWidth, screenHeight);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		glEnable(GL_DEPTH_TEST);

		return true;
	}

	void renderWindow::clear()
	{
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear the screen to a colour
	}

	void renderWindow::clear(float fRed, float fGreen, float fBlue, float fAlpha)
	{
		clampValue(0, 1, fRed);
		clampValue(0, 1, fGreen);
		clampValue(0, 1, fBlue);
		clampValue(0, 1, fAlpha);

		std::cout << fRed;

		glClearColor(fRed, fGreen, fBlue, fAlpha);// Clear the screen to a colour
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void renderWindow::swapBuffers()
	{
		//Check and call events and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void renderWindow::clampValue(float min, float max, float& value)
	{
		if (value < min)
		{
			value = min;
		}

		if (value > max)
		{
			value = max;
		}
	}

	void renderWindow::clampValue(int min, int max, int& value)
	{
		if (value < min)
		{
			value = min;
		}

		if (value > max)
		{
			value = max;
		}
	}
}