#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace axe
{
	class renderWindow
	{
	public:
		//constructor / deconstructor 
		renderWindow(int fscreenWidth, int fscreenHeight, std::string fwindowName);
		~renderWindow();
		void clear();
		void clear(float fred, float fgreen, float fblue, float falpha);
		void swapBuffers();

	private:
		GLFWwindow* window; //GLFW Winow
		
		int screenWidth{ 720 };//stores the screen width
		int screenHeight{ 480 };//stores the screen height
		

		bool setupGLFW(std::string fwindowName);//sets up GLFW
		//bool setupGlad();

		void clampValue(float min, float max, float& value);
		void clampValue(int min, int max, int& value);

	};
}


