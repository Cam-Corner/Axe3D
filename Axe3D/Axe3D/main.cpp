#include <iostream>
#include <GLFW/glfw3.h>
#include "renderWindow.h"

int main()
{
	axe::renderWindow window(720, 480, "Axe 3D");

	while (true)
	{
		//clear the screen
		window.clear(0.0f, 0.0f, 1.0f, 1.0f);

		//do stuff

		//swap buffer
		window.swapBuffers();

	}
}