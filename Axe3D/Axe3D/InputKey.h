#pragma once
#include "ButtonEnums.h"

namespace Axe
{


	class InputKey
	{
	public:
		InputKey() {}
		InputKey(Axe::KeyCode KeyCode);
		~InputKey();

		bool KeyDown();
		bool KeyUp();
		bool KeyRepeat();
		void Update();

	private:
		Axe::KeyCode _KeyCode;

		KeyState _KeyState = KeyState::None;
	};
}

