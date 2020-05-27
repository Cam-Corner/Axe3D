#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include "RenderWindow.h"
#include <iostream>

namespace Axe
{
	Camera::Camera()
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::SetFOV(const float fFOV)
	{
		_FOV = fFOV;
	}

	glm::mat4 Camera::GetViewMatrix()
	{
		/*glm::vec3 CameraDirection = glm::normalize(m_Position - m_Target);

		glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 CameraRight = glm::normalize(glm::cross(WorldUp, CameraDirection));

		glm::vec3 CameraUp = glm::cross(CameraDirection, CameraRight);*/

		//glm::mat4 ViewMatrix = glm::lookAt(m_Position, m_Position + m_ForwardVector, m_UpVector);
		glm::mat4 ViewMatrix = glm::lookAt(_Transform.GetLocation(), _Transform.GetLocation() + _Transform.GetForwardVector(), glm::vec3(0, 1.0f, 0));
		return ViewMatrix;
	}

	glm::mat4 Camera::GetProjectionMatrix()
	{
		float ScreenWidth = Axe::RenderWindow::GetScreenResolution().x;
		float ScreenHeight = Axe::RenderWindow::GetScreenResolution().y;

		glm::mat4 Projection = glm::perspective(glm::radians(70.0f), ScreenWidth / ScreenHeight, 0.1f, 10000.0f);

		return Projection;
	}
}