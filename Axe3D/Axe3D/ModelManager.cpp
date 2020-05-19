#include "ModelManager.h"

namespace Axe
{
	bool ModelManager::LoadModelImp(std::string Path, std::string ModelName)
	{
		if (_Models.find(ModelName) == _Models.end())
		{

			Axe::Model TempModel{ &Path };
			_Models[ModelName] = TempModel;

			return true;
		}

		std::cout << "ERROR::MODEL::MANAGER:: Failed to load Model - " << ModelName << "! Model name already exist's! \n";
		return false;
	}

	Model* ModelManager::GetModelImp(std::string ModelName)
	{
		if (_Models.size() > 0)
		{
			for (std::unordered_map<std::string, Axe::Model>::iterator
				It = _Models.begin(); It != _Models.end(); ++It)
			{
				if (It->first == ModelName)
				{
					return &(It->second);
					break; //Return already does this but ill just add it just incase
				}
			}
		}

		std::cout << "ERROR::MODEL::MANAGER::GET::MODEL:: Model name - " << ModelName << " does not exists! \n";
		return NULL;
	}

	bool ModelManager::RemoveModelImp(std::string ModelName)
	{
		for (std::unordered_map<std::string, Axe::Model>::iterator
			It = _Models.begin(); It != _Models.end(); ++It)
		{
			_Models.erase(It);
			return true;
			break;
		}

		std::cout << "ERROR::MODEL::MANAGER::REMOVE::MODEL:: Model name - " << ModelName << " does not exists! \n";
		return false;
	}

	void ModelManager::RemoveAllModelsImp()
	{
		_Models.empty();
	}

	void ModelManager::DrawStaticMeshesImp()
	{
		for (auto SM : _StaticMeshesNeedingToBeDrawn)
		{
			if (SM->GetModel() != NULL)
			{
				SM->Draw();
			}
		}
	}

	void ModelManager::AddStaticMeshImp(Axe::StaticMesh* StaticMesh)
	{
		_StaticMeshesNeedingToBeDrawn.push_back(StaticMesh);
	}

	void ModelManager::RemoveStaticMeshImp(Axe::StaticMesh* StaticMesh)
	{
		for (int i = 0; i < _StaticMeshesNeedingToBeDrawn.size(); i++)
		{
			if (_StaticMeshesNeedingToBeDrawn[i] == StaticMesh)
			{
				_StaticMeshesNeedingToBeDrawn.erase(_StaticMeshesNeedingToBeDrawn.begin(),
													_StaticMeshesNeedingToBeDrawn.begin() + i);

				break;
			}
		}
	}

}