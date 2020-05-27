#include "Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

namespace Axe
{
	Shader::Shader(std::string VertexShaderLocation, std::string FragmentShaderLocation)
	{
		std::string VSLine;
		std::string VSCode;
		std::ifstream VSFile;

		VSFile.open(VertexShaderLocation);
		if (VSFile.is_open())
		{
			while (VSFile)
			{
				std::getline(VSFile, VSLine);
				VSCode += VSLine + "\n";

				//std::cout << Line << "\n";
			}
		}
		else
		{
			std::cout << "SHADER::ERROR: FAILED TO READ VERTEX SHADER! \n";
		}
		const char* VertexShaderSource = VSCode.c_str();
		VSFile.close();

		std::string FSLine;
		std::string FSCode;
		std::ifstream FSFile;

		FSFile.open(FragmentShaderLocation);
		if (FSFile.is_open())
		{
			while (FSFile)
			{
				std::getline(FSFile, FSLine);
				FSCode += FSLine + "\n";

				//std::cout << Line << "\n";
			}
		}
		else
		{
			std::cout << "SHADER::ERROR: FAILED TO READ FRAGMENT SHADER! \n";
		}
		const char* FragmentShaderSource = FSCode.c_str();
		FSFile.close();


		//setup the vertex shader
		unsigned int VertexShader; // assign an int to store vertex shader ID
		VertexShader = glCreateShader(GL_VERTEX_SHADER); //create the vertex shader an ID
		glShaderSource(VertexShader, 1, &VertexShaderSource, NULL); // assign the vertex shader from the chars above
		glCompileShader(VertexShader);// compile the vertex shader

		//used for checking shader is succesfull
		int Success;
		char InfoLog[512];
		//
		glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &Success);//check if vertex shader compiled successfully
		if (!Success)
		{
			glGetShaderInfoLog(VertexShader, 512, NULL, InfoLog);
			std::cout << "SHADER::ERROR: VERTEX SHADER COMPILATION FAILED! \n " << InfoLog << "\n";
		}

		//set up fragment shader
		unsigned int FragmentShader; // assign an int to store fragment shader ID
		FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);//create the fragment shader an ID
		glShaderSource(FragmentShader, 1, &FragmentShaderSource, NULL);// assignt the fragment shader from the chars above
		glCompileShader(FragmentShader);// compile the fragment shader

		glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &Success); // check if fragment shader compiled successfully
		if (!Success)
		{
			glGetShaderInfoLog(FragmentShader, 512, NULL, InfoLog);
			std::cout << "SHADER::ERROR: FRAGMENT SHADER COMPILATION FAILED! \n " << InfoLog << "\n";
		}

		_ShaderProgramID = glCreateProgram();
		glAttachShader(_ShaderProgramID, VertexShader);
		glAttachShader(_ShaderProgramID, FragmentShader);
		glLinkProgram(_ShaderProgramID);

		glGetProgramiv(_ShaderProgramID, GL_LINK_STATUS, &Success);
		if (!Success)
		{
			glGetProgramInfoLog(_ShaderProgramID, 512, NULL, InfoLog);
			std::cout << "SHADER::ERROR: PROGRAM LINK FAILED! \n " << InfoLog << "\n";
		}

		//glUseProgram(ShaderProgramID);

		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);


		/*VSFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			PUTTING WHILE LOOP HERE CAUSED EXCEPTIONS
		}
		catch (std::ifstream::failure Error)
		{
			std::cout << "SHADER::ERROR: FAILED TO READ VERTEX SHADER! \n";
		}*/
	}

	Shader::~Shader()
	{

	}

	void Shader::UseProgram()
	{
		glUseProgram(_ShaderProgramID);
	}

	void Shader::SetInt(std::string UniformName, int Value) const
	{
		GLuint IntLocation = glGetUniformLocation(_ShaderProgramID, UniformName.c_str());
		glUniform1i(IntLocation, Value);
	}

	void Shader::SetBool(std::string UniformName, bool Value) const
	{
		GLuint BoolLocation = glGetUniformLocation(_ShaderProgramID, UniformName.c_str());
		glUniform1i(BoolLocation, Value);
	}

	void Shader::SetFloat(std::string UniformName, float Value) const
	{
		glUniform1f(glGetUniformLocation(_ShaderProgramID, UniformName.c_str()), Value);
	}

	void Shader::SetVec3(std::string UniformName, glm::vec3 Value) const
	{
		GLuint Vec3Location = glGetUniformLocation(_ShaderProgramID, UniformName.c_str());
		glUniform3fv(Vec3Location, 1, glm::value_ptr(Value));
	}

	void Shader::SetMat4(std::string UniformName, glm::mat4& Mat4) const
	{
		int Mat4Location = glGetUniformLocation(_ShaderProgramID, UniformName.c_str());
		glUniformMatrix4fv(Mat4Location, 1, GL_FALSE,  glm::value_ptr(Mat4));
	}
}