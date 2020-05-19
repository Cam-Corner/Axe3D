#pragma once
#include "Application.h"

extern Axe::Application* Axe::CreateApplication();

int main(int argc, char** argv)
{
	auto App = Axe::CreateApplication();
	App->Run();
	delete App;	
}


