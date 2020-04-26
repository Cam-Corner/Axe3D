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
		RenderWindow(const RenderWindow&) = delete;

		//Get instance of this class(because its a singleton)
		static RenderWindow& Get()
		{
			static RenderWindow _Window;
			return _Window;
		}

		// deconstructor 
		~RenderWindow();

		static bool Create(int ScreenWidth, int ScreenHeight, std::string WindowName) { return Get().CreateImp(ScreenWidth, ScreenHeight, WindowName); }
		static bool HasWindow() { return Get()._HasWindow; }

	private:
		//constructor
		RenderWindow() { }
		bool _HasWindow{ false };
		bool CreateImp(int ScreenWidth, int ScreenHeight, std::string WindowName);

	public:
		
		static bool IsOpen() { return Get().IsOpenImp(); }
		static void Clear() { Get().ClearImp(); }
		static void Clear(float Red, float Green, float Blue, float Alpha) { Get().ClearImp(Red, Green, Blue, Alpha); }
		static void SwapBuffers() { return Get().SwapBuffersImp(); }
		static GLFWwindow* GetGLFWWindow() { return Get().GetGLFWWindowImp(); }
		static void UpdateInput() { Get().UpdateInputImp(); }
		static glm::vec2 MousePosition() { return Get().MousePositionImp(); }
		static double GetMouseXOffset() { return Get().GetMouseXOffsetImp(); }
		static double GetMouseYOffset() { return Get().GetMouseYOffsetImp(); }
		static glm::vec2 GetScreenResolution() { return Get().GetScreenResolutionImp(); }

	private:
		bool IsOpenImp();
		void ClearImp();
		void ClearImp(float Red, float Green, float Blue, float Alpha);
		void SwapBuffersImp();
		glm::vec2 GetScreenResolutionImp() { return glm::vec2(_ScreenWidth, _ScreenHeight); }

		GLFWwindow* GetGLFWWindowImp()
		{
			if (_Window != NULL)
			{
				return _Window;
			}
			else
			{
				return NULL;
			}
		}

		///<summary>
		///*Updates the mouse movement
		///</summary>
		void UpdateInputImp();

		glm::vec2 MousePositionImp();
		double GetMouseXOffsetImp();
		double GetMouseYOffsetImp();
				
		GLFWwindow* _Window; //GLFW Window

		int _ScreenWidth{ 720 };//stores the screen width
		int _ScreenHeight{ 480 };//stores the screen height

		bool SetupGLFW(std::string WindowName);//sets up GLFW
		bool SetupGlad();//sets up GLAD
		void SetOpenGLSettings();

		void ClampValue(float Min, float Max, float& Value);
		void ClampValue(int Min, int Max, int& Value);

		//Mouse Variables
		bool _DoneMouseSetup{ false };
		double _LastMouseXPos{ 0 };
		double _LastMouseYPos{ 0 };
		double _MouseXOffset{ 0 };
		double _MouseYOffset{ 0 };
	};
}
