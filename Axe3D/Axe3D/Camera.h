#pragma once
#include <glm/glm.hpp>

namespace axe
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		void SetFOV(const float fFOV);
		void SetPosition(const glm::vec3 fPosition);
		void SetRotation(const glm::vec3 fRotation);

		glm::vec3 GetForwardVector() { return m_ForwardVector; }
		glm::vec3 GetUpVector() { return m_UpVector; }
		glm::vec3 GetRightVector();


		glm::mat4 GetViewMatrix();
		//const glm::mat4 GetProjectionMatrix() { return m_Projection; }

	private:
		float m_FOV{ 45.0f };
		float m_NearPlane{ 0.1f };
		float m_FarPlane{ 100.0f };

		glm::vec3 m_Position{ 0.0f, 0.0f, 0.0f};
		glm::vec3 m_ForwardVector{ 0.0f, 0.0f, -1.0f };
		glm::vec3 m_UpVector{ 0.0f, 1.0f, 0.0f };



	};
}

