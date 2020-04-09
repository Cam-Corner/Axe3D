#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Shader.h"
#include "Camera.h"

namespace axe
{
	class RenderWindow
	{
	public:
		//constructor / deconstructor 
		RenderWindow(int fScreenWidth, int fScreenHeight, std::string fWindowName);
		~RenderWindow();
		bool IsOpen();
		void Clear();
		void Clear(float fRed, float fGreen, float fBlue, float fAlpha);
		void SwapBuffers();

		GLFWwindow* GetGLFWWindow() 
		{
			if (m_Window != NULL)
			{
				return m_Window;
			}
			else
			{
				return NULL;
			}
		}

	private:
		GLFWwindow* m_Window; //GLFW Window

		int m_ScreenWidth{ 720 };//stores the screen width
		int m_ScreenHeight{ 480 };//stores the screen height

		bool SetupGLFW(std::string fWindowName);//sets up GLFW
		bool SetupGlad();//sets up GLAD

		void ClampValue(float fMin, float fMax, float& fValue);
		void ClampValue(int fMin, int fMax, int& fValue);


	};
}
