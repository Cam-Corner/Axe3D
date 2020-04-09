#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace axe
{
	Camera::Camera()
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::SetFOV(const float fFOV)
	{
		m_FOV = fFOV;
	}

	void Camera::SetPosition(const glm::vec3 fPosition)
	{
		m_Position = fPosition;
	}

	void Camera::SetRotation(const glm::vec3 fRotation)
	{
		//
	}

	glm::vec3 Camera::GetRightVector()
	{
		glm::vec3 CameraDirection = glm::normalize(m_Position - m_ForwardVector);

		glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 CameraRight = glm::normalize(glm::cross(m_ForwardVector, m_UpVector));
		return CameraRight;
	}

	glm::mat4 Camera::GetViewMatrix()
	{
		/*glm::vec3 CameraDirection = glm::normalize(m_Position - m_Target);

		glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 CameraRight = glm::normalize(glm::cross(WorldUp, CameraDirection));

		glm::vec3 CameraUp = glm::cross(CameraDirection, CameraRight);*/

		glm::mat4 ViewMatrix = glm::lookAt(m_Position, m_Position + m_ForwardVector, m_UpVector);

		return ViewMatrix;
	}
}