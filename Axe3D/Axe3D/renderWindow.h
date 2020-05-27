#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Shader.h"
#include "Camera.h"

namespace Axe
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

		static glm::vec2 GetScreenResolution() { return Get().GetScreenResolutionImp(); }
		static Axe::Camera* GetActiveCamera() { return Get().GetActiveCameraImp(); }
		static void SetActiveCamera(Axe::Camera* Camera) { Get()._ActiveCamera = Camera; }
		
		//window Settings
		static void SetWindowResolution(unsigned int Width, unsigned int Height) { Get().SetWindowResolutionImp(Width, Height); }
		static void SetFullScreen(bool Value) { Get().SetFullScreenImp(Value); }

		static void SetWindowTitle(std::string Title) { Get().SetWindowTitleImp(Title); }
		static std::string GetWindowTitle() { return Get().GetWindowTitleImp(); }

	private:
		bool IsOpenImp();
		void ClearImp();
		void ClearImp(float Red, float Green, float Blue, float Alpha);
		void SwapBuffersImp();
		glm::vec2 GetScreenResolutionImp() { return glm::vec2(_ScreenWidth, _ScreenHeight); }

		Axe::Camera* GetActiveCameraImp() { if (_ActiveCamera != NULL) return _ActiveCamera; }


		void SetWindowTitleImp(std::string Title) { _WindowTitle = Title; }
		std::string GetWindowTitleImp() { return _WindowTitle; }

		//WindowSettings
		void SetWindowResolutionImp(unsigned int Width, unsigned int Height);
		void SetFullScreenImp(bool Value);

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

		

		bool SetupGLFW(std::string WindowName);//sets up GLFW
		bool SetupGlad();//sets up GLAD
		void SetOpenGLSettings();

		void ClampValue(float Min, float Max, float& Value);
		void ClampValue(int Min, int Max, int& Value);

		Axe::Camera* _ActiveCamera;

	private:
		GLFWwindow* _Window; //GLFW Window

		int _ScreenWidth{ 720 }; //stores the screen width
		int _ScreenHeight{ 480 };//stores the screen height

		std::string _WindowTitle{"Title Not Set"};

	};
}
