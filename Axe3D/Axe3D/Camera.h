#pragma once
#include <glm/glm.hpp>
#include "Component.h"

namespace Axe
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		void SetFOV(const float fFOV);

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
		glm::mat4 GetProjectionMatrix();

	private:
		float _FOV{ 45.0f };
		float _NearPlane{ 0.1f };
		float _FarPlane{ 100.0f };

		//camera rotation clamp
		glm::vec3 m_MinRotationClamps{ 0, 0, 0 };
		glm::vec3 m_MaxRotationClamps{ 0, 0, 0 };

	};
}

