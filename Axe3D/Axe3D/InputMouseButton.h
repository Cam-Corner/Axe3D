#pragma once
#include "ButtonEnums.h"

namespace Axe
{
	class InputMouseButton
	{
	public:
		InputMouseButton() { }
		InputMouseButton(Axe::MouseButton Button) { _MouseButton = Button; }
		~InputMouseButton() { }

		bool ButtonDown();
		bool ButtonUp();
		bool ButtonRepeat();
		void Update();

	private:
		Axe::MouseButton _MouseButton;

		KeyState _KeyState = KeyState::None;
	};
}

