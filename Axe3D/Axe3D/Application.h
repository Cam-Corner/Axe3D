#pragma once
#include <iostream>
#include "RenderWindow.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <time.h>
#include "InputManager.h"
#include "ModelManager.h"

namespace Axe
{
	class Application
	{
	public:
		void Run();
		virtual ~Application();

	protected:
		//makes the class abstract so it can't be created. Means it has to be inhereted 
		Application();
		
		
		///<Summary>
		///This function will be run before the game loop starts
		///</Summary>
		virtual void Start() = 0;

		///<Summary>
		///This is the game loop that will be run once per frame
		///</Summary>
		virtual void Update() = 0;

		///<Summary>
		///this will be run after the game has ended
		///</Summary>
		virtual void End() = 0;

	private:
		

	private:

		int _FPS{ 0 };
		float _CurrentTime{ 1 };

	};

	Application* CreateApplication();
}

