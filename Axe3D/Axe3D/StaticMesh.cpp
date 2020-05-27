#include "StaticMesh.h"
#include <glm/gtc/matrix_transform.hpp>
#include "ModelManager.h"
#include "RenderWindow.h"

namespace Axe
{
	StaticMesh::StaticMesh()
	{
		
	}

	StaticMesh::~StaticMesh()
	{
		
	}

	bool StaticMesh::SetModel(Axe::Model* Model)
	{
		if (Model != NULL)
		{
			_Model = Model;
			return true;
		}

		std::cout << "ERROR::STATIC::MESH: Model is NULL \n";

		return false;
	}

	bool StaticMesh::SetModel(std::string* ModelName)
	{
		_Model = Axe::ModelManager::GetModel(*ModelName);

		if (_Model == NULL)
		{
			std::cout << "ERROR::STATIC::MESH: " << ModelName << " not found! \n";
			return false;
		}

		return true;
	}
	
	bool StaticMesh::Draw(Axe::Shader& Shader)
	{
		if (_Model != NULL)
		{
			Shader.UseProgram();

			glm::mat4 Projection = Axe::RenderWindow::GetActiveCamera()->GetProjectionMatrix();
			Shader.SetMat4("Projection", Projection);

			glm::mat4 View = Axe::RenderWindow::GetActiveCamera()->GetViewMatrix();
			Shader.SetMat4("View", View);

			glm::mat4 Model = _Transform.GetTransformMatrix();
			Shader.SetMat4("Model", Model);

			_Model->Draw(Shader);

			return true;
		}
		else
		{
			std::cout << "ERROR::STATIC::MESH: Static Mesh has no mesh attached! \n";

			return false;
		}

		std::cout << "ERROR::STATIC::MESH: Static Mesh has no shader! \n";

		return false;
	}
}