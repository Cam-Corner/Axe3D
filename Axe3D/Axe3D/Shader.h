#pragma once
#include <string>
#include <glm/glm.hpp>

namespace Axe
{
	class Shader
	{
	public:
		Shader(std::string VertexShaderLocation, std::string FragmentShaderLocation);
		Shader() {}
		~Shader();
		void UseProgram();
		
		void SetInt(std::string UniformName, int Value) const;
		void SetBool(std::string UniformName, bool Value) const;
		void SetFloat(std::string UniformName, float Value) const;
		
		void SetVec3(std::string UniformName, glm::vec3 Value) const;

		void SetMat4(std::string UniformName, glm::mat4& Mat4) const;

		unsigned int GetID() { return _ShaderProgramID; }
	private:
		unsigned int _ShaderProgramID;

	};
}

