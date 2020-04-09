#include <iostream>
#include "RenderWindow.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Mesh.h"
#include "stb_image.h"
#include <time.h>

struct sTriangle
{
	//float Vertices[24] = { -0.5f, 0.5f, 0.5f, //front top left 0
	//					-0.5f, -0.5f, 0.5f, // front bottem left 1
	//					0.5f, 0.5f, 0.5f, //front top right 2
	//					0.5f, -0.5f, 0.5f, //front bottem right 3 
	//					-0.5f, 0.5f, -0.5f, //back top left 4
	//					-0.5f, -0.5f, -0.5f, // back bottem left 5
	//					0.5f, 0.5f, -0.5f, //back top right 6
	//					0.5f, -0.5f, -0.5f /*back bottem right 7 */ };

	unsigned int Indices[36] = { 0, 1, 3,
								3, 2, 0,
								2, 6, 3,
								3, 7, 6,
								4, 5, 7,
								7, 6, 4,
								0, 4, 1,
								1, 5, 4,
								0, 4, 6,
								6, 2, 0,
								1, 4, 7,
								7, 3, 2};


	//float colour[3] = { 0.0f, 0.0f, 0.0f };

};

						//position           //texture coords
float Vertices[] = {   -0.5f, 0.5f, 0.5f,      0.0f, 1.0f, //front top left 0
					   -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, // front bottem left 1
						0.5f, 0.5f, 0.5f,      1.0f, 1.0f, //front top right 2

					   -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, // front bottem left 1
						0.5f, 0.5f, 0.5f,      1.0f, 1.0f, //front top right 2
						0.5f, -0.5f, 0.5f,     1.0f, 0.0f, //front bottem right 3 

					   -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, // back bottem left 1
						0.5f, 0.5f, -0.5f,     1.0f, 1.0f, //back top right 2
						0.5f, -0.5f, -0.5f,    1.0f, 0.0f, //back bottem right 3 
										                  
					   -0.5f, 0.5f, -0.5f,     0.0f, 1.0f, //back top left 0
					   -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, //back bottem left 1
						0.5f, 0.5f, -0.5f,     1.0f, 1.0f, //back top right 2
										                  
					   -0.5f, 0.5f, 0.5f,      0.0f, 0.0f, //front top left 0
						0.5f, 0.5f, 0.5f,      1.0f, 0.0f, //front top right 2
					   -0.5f, 0.5f, -0.5f,     0.0f, 1.0f, //back top left 0
					   					                  
					   -0.5f, 0.5f, -0.5f,     0.0f, 1.0f, //back top left 0
					    0.5f, 0.5f, -0.5f,     1.0f, 1.0f, //back top right 2
					    0.5f, 0.5f, 0.5f,      1.0f, 0.0f, //front top right 2
					   					                  
					   -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, //front bottom left 0
					    0.5f, -0.5f, 0.5f,     1.0f, 0.0f, //front bottom right 2
					   -0.5f, -0.5f, -0.5f,    0.0f, 1.0f, //back bottom left 0
					   					                  
					   -0.5f, -0.5f, -0.5f,    0.0f, 1.0f, //back bottom left 0
					    0.5f, -0.5f, -0.5f,    1.0f, 1.0f, //back bottom right 2
					    0.5f, -0.5f, 0.5f,     1.0f, 0.0f, //front bottom right 2
					   					                  
					   -0.5f, 0.5f, 0.5f,      1.0f, 0.0f, //front top left 0
					   -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, // front bottem left 1
					   -0.5f, 0.5f, -0.5f,     1.0f, 1.0f, //back top left 0
										                   
					   -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, //front bottem left 1
					   -0.5f, 0.5f, -0.5f,     1.0f, 1.0f, //back top left 0				   
					   -0.5f, -0.5f, -0.5f,    0.0f, 1.0f, //back bottem left 1
										                   
	                    0.5f, 0.5f, 0.5f,      1.0f, 0.0f, //front top right 0
					    0.5f, -0.5f, 0.5f,     0.0f, 0.0f, // front bottem right 1
					    0.5f, 0.5f, -0.5f,     1.0f, 1.0f, //back top right 0
										                   
					    0.5f, -0.5f, 0.5f,     0.0f, 0.0f, //front bottem right 1
					    0.5f, 0.5f, -0.5f,     1.0f, 1.0f, //back top right 0				   
					    0.5f, -0.5f, -0.5f,    0.0f, 1.0f, //back bottem right 1
};


int main()
{
	srand(time(NULL));
	axe::RenderWindow Window(1280, 720, "Axe 3D");
	/*sTriangle* Triangle;
	Triangle = new sTriangle;*/

	//used for drawing the rectangle
	unsigned int VBO, VAO, EBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Triangle->Indices), Triangle->Indices, GL_STATIC_DRAW);*/

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	axe::Shader MyShader{ std::string("Shaders/VertexShader.txt"), std::string("Shaders/FragmentShader.txt") };


	stbi_set_flip_vertically_on_load(true);


	unsigned int Texture1ID, Texture2ID;
	glGenTextures(1, &Texture1ID);
	glBindTexture(GL_TEXTURE_2D, Texture1ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int Width, Height, NRChannels;
	unsigned char* Data = stbi_load("Textures/Texture01.png", &Width, &Height, &NRChannels, 0);
	if (Data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "IMAGE::ERROR: Failed to load image!\n";
	}
	stbi_image_free(Data);

	glGenTextures(1, &Texture2ID);
	glBindTexture(GL_TEXTURE_2D, Texture2ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	//int Width, Height, NRChannels;
	Data = stbi_load("Textures/Texture02.png", &Width, &Height, &NRChannels, 0);
	if (Data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "IMAGE::ERROR: Failed to load image!\n";
	}

	stbi_image_free(Data);


	glEnable(GL_DEPTH_TEST);

	MyShader.UseProgram();
	glUniform1i(glGetUniformLocation(MyShader.GetID(), "Texture1"), 0);
	glUniform1i(glGetUniformLocation(MyShader.GetID(), "Texture2"), 1);

	bool Pressed = false;
	bool DoneOnce = false;
	std::vector<glm::vec3> Positions;

	for (int i = 0; i < 10; i++)
	{
		float x = rand() % 6 - 3;
		float y = rand() % 6 - 3;
		float z = rand() % 5 + 2;

		z = z * -1;

		Positions.push_back(glm::vec3(x, y, z));
	}

	glm::vec3 CameraPos{ 0, 0, 0 };
	float CameraSpeed{ 0.05f };
	axe::Camera MyCamera;

	while (Window.IsOpen())
	{
		//clear the screen
		//Window.Clear(0.0f, 0.0f, 1.0f, 1.0f);
		Window.Clear();
		//do stuff
		MyShader.UseProgram();
		
		if (glfwGetKey(Window.GetGLFWWindow(), GLFW_KEY_W) == GLFW_PRESS)
		{
			CameraPos += MyCamera.GetForwardVector() * CameraSpeed;
			MyCamera.SetPosition(CameraPos);
		}

		if (glfwGetKey(Window.GetGLFWWindow(), GLFW_KEY_A) == GLFW_PRESS)
		{
			CameraPos -= MyCamera.GetRightVector() * CameraSpeed;
			MyCamera.SetPosition(CameraPos);
		}
		
		if (glfwGetKey(Window.GetGLFWWindow(), GLFW_KEY_S) == GLFW_PRESS)
		{
			CameraPos -= MyCamera.GetForwardVector() * CameraSpeed;
			MyCamera.SetPosition(CameraPos);
		}

		if (glfwGetKey(Window.GetGLFWWindow(), GLFW_KEY_D) == GLFW_PRESS)
		{
			CameraPos += MyCamera.GetRightVector() * CameraSpeed;
			MyCamera.SetPosition(CameraPos);
		}

		glm::mat4 View = MyCamera.GetViewMatrix();
		View = glm::translate(View, glm::vec3(0.0f, 0.0f, 0.0f));
		MyShader.SetMat4("View", View);

		if (glfwGetKey(Window.GetGLFWWindow(), GLFW_KEY_R) == GLFW_PRESS)
		{
			if (!Pressed)
			{
				for (int i = 0; i < Positions.size(); i++)
				{
					float x = rand() % 10 - 5;
					float y = rand() % 10 - 5;
					float z = rand() % 5 + 5;

					z = z * -1;

					Positions[i] = glm::vec3(x, y, z);
				}

				Pressed = true;
			}
		}
		else
		{
			Pressed = false;
		}

		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 720.0f / 480.0f, 0.1f, 100.0f);
		MyShader.SetMat4("Projection", Projection);

		//MyCube.Draw();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture1ID);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, Texture2ID);
		glBindVertexArray(VAO);

		for (int i = 0; i < Positions.size(); i++)
		{
			glm::mat4 Model = glm::mat4(1.0f);
			//Model = glm::rotate(Model, (float)glfwGetTime() * glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f));
			Model = glm::translate(Model, Positions[i]);
			MyShader.SetMat4("Model", Model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			
			if(!DoneOnce)
				std::cout << Positions[i].x << "," << Positions[i].y << "," << Positions[i].z << "\n";
		}
		DoneOnce = true;
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		//glDrawElements(GL_TRIANGLES, 32, GL_UNSIGNED_INT, 0);
		//swap buffer
		Window.SwapBuffers();
	}

	return 0;
}