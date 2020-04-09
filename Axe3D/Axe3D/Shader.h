#pragma once
#include <string>
#include <glm/glm.hpp>

namespace axe
{
	class Shader
	{
	public:
		Shader(std::string fVertexShaderLocation, std::string fFragmentShaderLocation);
		~Shader();
		void UseProgram();
		
		void SetInt(std::string fVariableName, int fValue) const;
		void SetBool(std::string fVariableName, bool fValue) const;
		void SetFloat(std::string fVariableName, float fValue) const;

		void SetMat4(std::string fUniformName, glm::mat4& fMat4) const;

		unsigned int GetID() { return m_ShaderProgramID; }
	private:
		unsigned int m_ShaderProgramID;

	};
}

