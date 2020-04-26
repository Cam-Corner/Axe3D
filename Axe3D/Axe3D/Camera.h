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
		/*void AddPitch(float fAmount);
		void AddYaw(float fAmount);
		void AddRoll(float fAmount);*/

		///<summary>
		///*Gets the camera's forward vector
		///</summary>
		glm::vec3 GetForwardVector() { return m_ForwardVector; }
		
		///<summary>
		///*Gets the camera's up vector
		///</summary>
		glm::vec3 GetUpVector() { return m_UpVector; }
		
		///<summary>
		///*Gets the camera's right vector
		///</summary>
		glm::vec3 GetRightVector();

		///<summary>
		///*Clamps the camera's Pitch
		///* If you do not want it clamped, put both values at 0
		///</summary>
		void ClampPitch(float fMin, float fMax);
		
		///<summary>
		///*Clamps the camera's Yaw
		///* If you do not want it clamped, put both values at 0
		///</summary>
		void ClampYaw(float fMin, float fMax);

		///<summary>
		///*Clamps the camera's Roll
		///*If you do not want it clamped, put both values at 0
		///</summary>
		void ClampRoll(float fMin, float fMax);

		glm::mat4 GetViewMatrix();
		//const glm::mat4 GetProjectionMatrix() { return m_Projection; }

	private:
		float m_FOV{ 45.0f };
		float m_NearPlane{ 0.1f };
		float m_FarPlane{ 100.0f };

		glm::vec3 m_Position{ 0.0f, 0.0f, 0.0f};
		glm::vec3 m_ForwardVector{ 0.0f, 0.0f, 0.0f };
		glm::vec3 m_UpVector{ 0.0f, 1.0f, 0.0f };

		//camera rotation clamp
		glm::vec3 m_MinRotationClamps{ 0, 0, 0 };
		glm::vec3 m_MaxRotationClamps{ 0, 0, 0 };

	};
}

