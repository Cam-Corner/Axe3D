#pragma once
#include "ButtonEnums.h"

namespace axe
{
	enum KeyState
	{
		OnPressed, // the frame the key was pressed
		Repeat, // if the key is being held down
		OnReleased, // the frame the key was released
		None, // if the key isn't being held down or pressed
	};

	class InputKey
	{
	public:
		InputKey() {}
		InputKey(axe::KeyCode KeyCode);
		~InputKey();

		bool KeyDown();
		bool KeyUp();
		bool KeyRepeat();
		void Update();

	private:
		axe::KeyCode _KeyCode;

		KeyState _KeyState = KeyState::None;
	};
}

