#include "InputMouseButton.h"
#include "RenderWindow.h"

namespace Axe
{
	bool InputMouseButton::ButtonDown()
	{
		return _KeyState == KeyState::OnPressed;
	}

	bool InputMouseButton::ButtonUp()
	{
		return _KeyState == KeyState::OnReleased;
	}

	bool InputMouseButton::ButtonRepeat()
	{
		return _KeyState == KeyState::Repeat || _KeyState == KeyState::OnPressed;
	}

	void InputMouseButton::Update()
	{
		if (_KeyState == KeyState::None)
		{
			if (glfwGetMouseButton(Axe::RenderWindow::GetGLFWWindow(), _MouseButton) == GLFW_PRESS)
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
			bool flag = glfwGetMouseButton(Axe::RenderWindow::GetGLFWWindow(), _MouseButton) == GLFW_RELEASE;

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