#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <istream>

Axe::Transform::Transform()
{
}

Axe::Transform::~Transform()
{
}

void Axe::Transform::SetLocation(glm::vec3 Location)
{
	_Location = Location;
}

void Axe::Transform::SetRotation(glm::vec3 Rotation)
{
	//set rotation
	_Rotation = Rotation;

	//work out forward vector
	/*glm::vec3 ForwardDirection{ 0, 0, 0 };
	ForwardDirection.x = cos(glm::radians(_Rotation.y)) * cos(glm::radians(_Rotation.x));
	ForwardDirection.y = sin(glm::radians(_Rotation.x));
	ForwardDirection.z = sin(glm::radians(_Rotation.y)) * cos(glm::radians(_Rotation.x));
	_ForwardVector = glm::normalize(ForwardDirection);*/

	glm::mat4 InvertedTrasnformMatrix = glm::inverse(GetTransformMatrix());
	glm::vec3 ForwardVector = glm::normalize(glm::vec3(InvertedTrasnformMatrix[2]));
	_ForwardVector = ForwardVector;

	//work out right vector
	glm::vec3 RightDirection = glm::normalize(_Location - _ForwardVector);

	glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Right = glm::normalize(glm::cross(_ForwardVector, WorldUp));
	_RightVector = Right;

	//work out up vector
	_UpVector = glm::cross(_ForwardVector, _RightVector);
}

void Axe::Transform::SetScale(glm::vec3 Scale)
{
	_Scale = Scale;
}

glm::mat4 Axe::Transform::GetTransformMatrix()
{
	glm::mat4 TransformMatrix = glm::mat4(1.0f);

	//Translation
	TransformMatrix = glm::translate(TransformMatrix, _Location);

	//Rotation
	TransformMatrix = glm::rotate(TransformMatrix, glm::radians(_Rotation.x), glm::vec3(1.0f, 0, 0));
	TransformMatrix = glm::rotate(TransformMatrix, glm::radians(_Rotation.y), glm::vec3(0, 1.0f, 0));
	TransformMatrix = glm::rotate(TransformMatrix, glm::radians(_Rotation.z), glm::vec3(0, 0, 1.0f));

	//Scale
	TransformMatrix = glm::scale(TransformMatrix, _Scale);

	return TransformMatrix;
}
