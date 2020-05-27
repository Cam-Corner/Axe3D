#pragma once
#include <iostream>
#include "Model.h"
#include <unordered_map>
#include "StaticMesh.h"

namespace Axe
{
	class ModelManager
	{
	public:
		ModelManager(const ModelManager&) = delete;

		static ModelManager& Get()
		{
			static ModelManager _ModelManager;
			return _ModelManager;
		}

		~ModelManager() {}

		friend class StaticMesh;
		friend class Application;
	private:
		ModelManager() {}



	public:
		static bool LoadModel(std::string Path, std::string ModelName) { return Get().LoadModelImp(Path, ModelName); }
		static Model* GetModel(std::string ModelName) { return Get().GetModelImp(ModelName); }
		static bool RemoveModel(std::string ModelName) { return Get().RemoveModelImp(ModelName); }
		static void RemoveAllModels() { Get().RemoveAllModelsImp(); }

	private:
		bool LoadModelImp(std::string Path, std::string ModelName);
		Model* GetModelImp(std::string ModelName);
		bool RemoveModelImp(std::string ModelName);
		void RemoveAllModelsImp();

		std::unordered_map<std::string, Axe::Model> _Models;
	};
}

