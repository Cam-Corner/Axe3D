#pragma once
#include <iostream>
#include <glm/glm.hpp>

namespace Axe
{
	class Transform
	{
	public:
		Transform();
		~Transform();

		const glm::vec3& GetLocation() { return _Location; }
		const glm::vec3& GetRotation() { return _Rotation; }
		const glm::vec3& GetScale() { return _Scale; }

		void SetLocation(glm::vec3 Location);
		void SetRotation(glm::vec3 Rotation);
		void SetScale(glm::vec3 Scale);

		glm::mat4 GetTransformMatrix();

		///<summary>
		///*Gets the camera's forward vector
		///</summary>
		const glm::vec3 GetForwardVector() { return _ForwardVector; }

		///<summary>
		///*Gets the camera's up vector
		///</summary>
		const glm::vec3 GetUpVector() { return _UpVector; }

		///<summary>
		///*Gets the camera's right vector
		///</summary>
		const glm::vec3 GetRightVector() { return _RightVector; } 

	private:
		glm::vec3 _Location{ 0, 0, 0 };
		glm::vec3 _Rotation{ 0, 0, 0 };
		glm::vec3 _Scale{ 1, 1, 1 };

		glm::vec3 _ForwardVector{ 0.0f, 0.0f, 0.0f };
		glm::vec3 _RightVector{ 0.0f, 1.0f, 0.0f };
		glm::vec3 _UpVector{ 0.0f, 1.0f, 0.0f };
	};
}

