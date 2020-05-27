#pragma once
#include "Transform.h"

namespace Axe
{
	class Component
	{
	public:
		Transform& GetTransform() { return _Transform; }

	protected:
		Component();
		~Component();
		Transform _Transform;
	};
}

