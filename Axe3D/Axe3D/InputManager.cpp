#include "InputManager.h"
#include "RenderWindow.h"
#include <GLFW/glfw3.h>
#include <iostream>

namespace Axe
{
	InputManager::InputManager()
	{
		SetupKeys();
		glfwSetInputMode(Axe::RenderWindow::GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	bool InputManager::GetKeyDownImp(KeyCode Key)
	{
		if (_Keys.find(Key) != _Keys.end())
		{
			return _Keys[Key].KeyDown();
		}

		return false;
	}

	bool InputManager::GetKeyUpImp(KeyCode Key)
	{
		if (_Keys.find(Key) != _Keys.end())
		{
			return _Keys[Key].KeyUp();
		}

		return false;
	}

	bool InputManager::GetKeyImp(KeyCode Key)
	{
		if (_Keys.find(Key) != _Keys.end())
		{
			return _Keys[Key].KeyRepeat();
		}

		return false;
	}


	bool InputManager::GetButtonDownImp(MouseButton Button)
	{
		if (_MouseButtons.find(Button) != _MouseButtons.end())
		{
			return _MouseButtons[Button].ButtonDown();
		}

		return false;
	}

	bool InputManager::GetButtonUpImp(MouseButton Button)
	{
		if (_MouseButtons.find(Button) != _MouseButtons.end())
		{
			return _MouseButtons[Button].ButtonUp();
		}

		return false;
	}

	bool InputManager::GetButtonImp(MouseButton Button)
	{
		if (_MouseButtons.find(Button) != _MouseButtons.end())
		{
			return _MouseButtons[Button].ButtonRepeat();
		}

		return false;
	}

	void InputManager::UpdateImp()
	{
		for (std::unordered_map<Axe::KeyCode, Axe::InputKey>::iterator
			It = _Keys.begin(); It != _Keys.end(); ++It)
		{
			It->second.Update();
		}

		for (std::unordered_map<Axe::MouseButton, Axe::InputMouseButton>::iterator
			It = _MouseButtons.begin(); It != _MouseButtons.end(); ++It)
		{
			It->second.Update();
		}

		double CurrentMouseX, CurrentMouseY;
		glfwGetCursorPos(Axe::RenderWindow::GetGLFWWindow(), &CurrentMouseX, &CurrentMouseY);

		_MouseXOffset = _LastMouseXPos - CurrentMouseX;
		_MouseYOffset = _LastMouseYPos - CurrentMouseY;

		_LastMouseXPos = CurrentMouseX;
		_LastMouseYPos = CurrentMouseY;

		if (glfwGetKey(Axe::RenderWindow::GetGLFWWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetInputMode(Axe::RenderWindow::GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}

		if (glfwGetMouseButton(Axe::RenderWindow::GetGLFWWindow(), GLFW_MOUSE_BUTTON_LEFT))
		{
			glfwSetInputMode(Axe::RenderWindow::GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	}

	//float LastXVal, LastYVal;

	//void mouse_CallbackImp(GLFWwindow* Window, double NewXpos, double NewYpos)
	//{
	//	float OffsetX = LastXVal - NewXpos;
	//	float OffsetY = LastYVal - NewYpos;
	//	std::cout << "\n" << OffsetX << ", " << OffsetY;

	//	LastXVal = NewXpos;
	//	LastYVal = NewYpos;
	//}

	double InputManager::GetMouseXOffsetImp()
	{
		return _MouseXOffset;
	}

	double InputManager::GetMouseYOffsetImp()
	{
		return _MouseYOffset;
	}

	glm::vec2 InputManager::MousePositionImp()
	{
		double CurrentMouseX, CurrentMouseY;
		glfwGetCursorPos(Axe::RenderWindow::GetGLFWWindow(), &CurrentMouseX, &CurrentMouseY);

		return glm::vec2(CurrentMouseX, CurrentMouseY);
	}

	void InputManager::SetupKeys()
	{
		AddKeyToMap(Axe::KeyCode::SPACE);
		AddKeyToMap(Axe::KeyCode::APOSTROPHE);
		AddKeyToMap(Axe::KeyCode::COMMA);
		AddKeyToMap(Axe::KeyCode::MINUS);
		AddKeyToMap(Axe::KeyCode::PERIOD);
		AddKeyToMap(Axe::KeyCode::SLASH);
		AddKeyToMap(Axe::KeyCode::Num0);
		AddKeyToMap(Axe::KeyCode::Num1);
		AddKeyToMap(Axe::KeyCode::Num2);
		AddKeyToMap(Axe::KeyCode::Num3);
		AddKeyToMap(Axe::KeyCode::Num4);
		AddKeyToMap(Axe::KeyCode::Num5);
		AddKeyToMap(Axe::KeyCode::Num6);
		AddKeyToMap(Axe::KeyCode::Num7);
		AddKeyToMap(Axe::KeyCode::Num8);
		AddKeyToMap(Axe::KeyCode::Num9);
		AddKeyToMap(Axe::KeyCode::SEMICOLON);
		AddKeyToMap(Axe::KeyCode::EQUAL);
		AddKeyToMap(Axe::KeyCode::A);
		AddKeyToMap(Axe::KeyCode::B);
		AddKeyToMap(Axe::KeyCode::C);
		AddKeyToMap(Axe::KeyCode::D);
		AddKeyToMap(Axe::KeyCode::E);
		AddKeyToMap(Axe::KeyCode::F);
		AddKeyToMap(Axe::KeyCode::G);
		AddKeyToMap(Axe::KeyCode::H);
		AddKeyToMap(Axe::KeyCode::I);
		AddKeyToMap(Axe::KeyCode::J);
		AddKeyToMap(Axe::KeyCode::K);
		AddKeyToMap(Axe::KeyCode::L);
		AddKeyToMap(Axe::KeyCode::M);
		AddKeyToMap(Axe::KeyCode::N);
		AddKeyToMap(Axe::KeyCode::O);
		AddKeyToMap(Axe::KeyCode::P);
		AddKeyToMap(Axe::KeyCode::Q);
		AddKeyToMap(Axe::KeyCode::R);
		AddKeyToMap(Axe::KeyCode::S);
		AddKeyToMap(Axe::KeyCode::T);
		AddKeyToMap(Axe::KeyCode::U);
		AddKeyToMap(Axe::KeyCode::V);
		AddKeyToMap(Axe::KeyCode::W);
		AddKeyToMap(Axe::KeyCode::X);
		AddKeyToMap(Axe::KeyCode::Y);
		AddKeyToMap(Axe::KeyCode::Z);
		AddKeyToMap(Axe::KeyCode::LEFT_BRACKET);
		AddKeyToMap(Axe::KeyCode::BACKSLASH);
		AddKeyToMap(Axe::KeyCode::RIGHT_BRACKET);
		AddKeyToMap(Axe::KeyCode::ACCENT);
		AddKeyToMap(Axe::KeyCode::ESCAPE);
		AddKeyToMap(Axe::KeyCode::ENTER);
		AddKeyToMap(Axe::KeyCode::TAB);
		AddKeyToMap(Axe::KeyCode::BACKSPACE);
		AddKeyToMap(Axe::KeyCode::INSERT);
		AddKeyToMap(Axe::KeyCode::DELETE);
		AddKeyToMap(Axe::KeyCode::RIGHT);
		AddKeyToMap(Axe::KeyCode::LEFT);
		AddKeyToMap(Axe::KeyCode::DOWN);
		AddKeyToMap(Axe::KeyCode::UP);
		AddKeyToMap(Axe::KeyCode::PAGE_UP);
		AddKeyToMap(Axe::KeyCode::PAGE_DOWN);
		AddKeyToMap(Axe::KeyCode::HOME);
		AddKeyToMap(Axe::KeyCode::END);
		AddKeyToMap(Axe::KeyCode::CAPS_LOCK);
		AddKeyToMap(Axe::KeyCode::SCROLL_LOCK);
		AddKeyToMap(Axe::KeyCode::NUM_LOCK);
		AddKeyToMap(Axe::KeyCode::PRINT_SCREEN);
		AddKeyToMap(Axe::KeyCode::PAUSE);
		AddKeyToMap(Axe::KeyCode::F1);
		AddKeyToMap(Axe::KeyCode::F2);
		AddKeyToMap(Axe::KeyCode::F3);
		AddKeyToMap(Axe::KeyCode::F4);
		AddKeyToMap(Axe::KeyCode::F5);
		AddKeyToMap(Axe::KeyCode::F6);
		AddKeyToMap(Axe::KeyCode::F7);
		AddKeyToMap(Axe::KeyCode::F8);
		AddKeyToMap(Axe::KeyCode::F9);
		AddKeyToMap(Axe::KeyCode::F10);
		AddKeyToMap(Axe::KeyCode::F11);
		AddKeyToMap(Axe::KeyCode::F12);
		AddKeyToMap(Axe::KeyCode::F13);
		AddKeyToMap(Axe::KeyCode::F14);
		AddKeyToMap(Axe::KeyCode::F15);
		AddKeyToMap(Axe::KeyCode::F16);
		AddKeyToMap(Axe::KeyCode::F17);
		AddKeyToMap(Axe::KeyCode::F18);
		AddKeyToMap(Axe::KeyCode::F19);
		AddKeyToMap(Axe::KeyCode::F20);
		AddKeyToMap(Axe::KeyCode::F21);
		AddKeyToMap(Axe::KeyCode::F22);
		AddKeyToMap(Axe::KeyCode::F23);
		AddKeyToMap(Axe::KeyCode::F24);
		AddKeyToMap(Axe::KeyCode::F25);
		AddKeyToMap(Axe::KeyCode::KP_Num0);
		AddKeyToMap(Axe::KeyCode::KP_Num1);
		AddKeyToMap(Axe::KeyCode::KP_Num2);
		AddKeyToMap(Axe::KeyCode::KP_Num3);
		AddKeyToMap(Axe::KeyCode::KP_Num4);
		AddKeyToMap(Axe::KeyCode::KP_Num5);
		AddKeyToMap(Axe::KeyCode::KP_Num6);
		AddKeyToMap(Axe::KeyCode::KP_Num7);
		AddKeyToMap(Axe::KeyCode::KP_Num8);
		AddKeyToMap(Axe::KeyCode::KP_Num9);
		AddKeyToMap(Axe::KeyCode::KP_DECIMAL);
		AddKeyToMap(Axe::KeyCode::KP_DIVIDE);
		AddKeyToMap(Axe::KeyCode::KP_MULTIPLY);
		AddKeyToMap(Axe::KeyCode::KP_SUBTRACT);
		AddKeyToMap(Axe::KeyCode::KP_ADD);
		AddKeyToMap(Axe::KeyCode::KP_ENTER);
		AddKeyToMap(Axe::KeyCode::KP_EQUAL);
		AddKeyToMap(Axe::KeyCode::LEFT_SHIFT);
		AddKeyToMap(Axe::KeyCode::LEFT_CONTROL);
		AddKeyToMap(Axe::KeyCode::LEFT_ALT);
		AddKeyToMap(Axe::KeyCode::RIGHT_SHIFT);
		AddKeyToMap(Axe::KeyCode::RIGHT_CONTROL);
		AddKeyToMap(Axe::KeyCode::RIGHT_ALT);

		AddMouseButtonToMap(Axe::MouseButton::LEFT_BUTTON);
		AddMouseButtonToMap(Axe::MouseButton::MIDDLE_BUTTON);
		AddMouseButtonToMap(Axe::MouseButton::RIGHT_BUTTON);
		AddMouseButtonToMap(Axe::MouseButton::EXTRA_BUTTON1);
		AddMouseButtonToMap(Axe::MouseButton::EXTRA_BUTTON2);
		AddMouseButtonToMap(Axe::MouseButton::EXTRA_BUTTON3);
		AddMouseButtonToMap(Axe::MouseButton::EXTRA_BUTTON4);
		AddMouseButtonToMap(Axe::MouseButton::LAST_BUTTON);

	}

	void InputManager::AddKeyToMap(Axe::KeyCode Key)
	{
		_Keys[Key] = Axe::InputKey(Key);
	}

	void InputManager::AddMouseButtonToMap(Axe::MouseButton Button)
	{
		_MouseButtons[Button] = Axe::InputMouseButton(Button);
	}
}