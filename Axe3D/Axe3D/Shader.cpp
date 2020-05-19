#include "Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

namespace Axe
{
	Shader::Shader(std::string fVertexShaderLocation, std::string fFragmentShaderLocation)
	{
		std::string VSLine;
		std::string VSCode;
		std::ifstream VSFile;

		VSFile.open(fVertexShaderLocation);
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

		FSFile.open(fFragmentShaderLocation);
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
			std::cout << "SHADER::ERROR: VERTEX SHADER COMpILATION FAILED! \n " << InfoLog << "\n";
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

		m_ShaderProgramID = glCreateProgram();
		glAttachShader(m_ShaderProgramID, VertexShader);
		glAttachShader(m_ShaderProgramID, FragmentShader);
		glLinkProgram(m_ShaderProgramID);

		glGetProgramiv(m_ShaderProgramID, GL_LINK_STATUS, &Success);
		if (!Success)
		{
			glGetProgramInfoLog(m_ShaderProgramID, 512, NULL, InfoLog);
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
		glUseProgram(m_ShaderProgramID);
	}

	void Shader::SetInt(std::string fVariableName, int fValue) const
	{

	}

	void Shader::SetBool(std::string fVariableName, bool fValue) const
	{

	}

	void Shader::SetFloat(std::string fVariableName, float fValue) const
	{
		glUniform1f(glGetUniformLocation(m_ShaderProgramID, fVariableName.c_str()), fValue);
	}

	void Shader::SetMat4(std::string fUniformName, glm::mat4& fMat4) const
	{
		int Mat4Location = glGetUniformLocation(m_ShaderProgramID, fUniformName.c_str());
		glUniformMatrix4fv(Mat4Location, 1, GL_FALSE,  glm::value_ptr(fMat4));
	}
}