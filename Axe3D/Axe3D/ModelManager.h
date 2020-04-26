#pragma once
#include <iostream>
#include "Model.h"


namespace axe
{
	class ModelManager
	{
	public:
		static ModelManager& Get()
		{
			static ModelManager _ModelManager;
			return _ModelManager;
		}

		~ModelManager();

	private:
		ModelManager();

	public:
		static bool LoadModel(std::string* Path, std::string ModelName) { return Get().LoadModelImp(Path, ModelName); }
		static Model GetModel(std::string ModelName) { return Get().GetModelImp(ModelName); }

	private:
		bool LoadModelImp(std::string* Path, std::string ModelName);
		Model GetModelImp(std::string ModelName);

	};
}

