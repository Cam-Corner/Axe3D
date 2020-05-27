#pragma once
#include "Component.h"

namespace Axe
{
	class Light : public Component
	{
	public:
		Light();
		~Light();

		glm::vec3 GetIntensity() { return _Intensity; }
		void SetIntensity(glm::vec3 Intensity) { _Intensity = Intensity; }

		float GetRange() { return _Range; }
		void SetRange(float Range) { _Range = Range; }

	private:
		unsigned int _ID{ 0 };

		glm::vec3 _Intensity;
		float _Range;


	};
}

