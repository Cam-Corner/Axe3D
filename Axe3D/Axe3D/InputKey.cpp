#include "InputKey.h"
#include "RenderWindow.h"
#include <iostream>

namespace Axe
{
	InputKey::InputKey(Axe::KeyCode KeyCode)
	{
		_KeyCode = KeyCode;
	}

	InputKey::~InputKey()
	{

	}

	bool InputKey::KeyDown()
	{
		return _KeyState == KeyState::OnPressed;
	}

	bool InputKey::KeyUp()
	{
		return _KeyState == KeyState::OnReleased;
	}

	bool InputKey::KeyRepeat()
	{		
		return _KeyState == KeyState::Repeat || _KeyState == KeyState::OnPressed;
	}

	void InputKey::Update()
	{
		if (_KeyState == KeyState::None)
		{
			if (glfwGetKey(Axe::RenderWindow::GetGLFWWindow(), _KeyCode) == GLFW_PRESS)
			{
				_KeyState = KeyState::OnPressed;
			}
		}
		else if (_KeyState == KeyState::OnReleased)
		{
			_KeyState = KeyState::None;
		}
		else if (_KeyState == KeyState::Repeat)
		{
			bool flag = glfwGetKey(Axe::RenderWindow::GetGLFWWindow(), _KeyCode) == GLFW_RELEASE;

			if (flag)
			{
				_KeyState = KeyState::OnReleased;
			}
		}
		else if (_KeyState == KeyState::OnPressed)
		{
			_KeyState = KeyState::Repeat;
		}
	}
}