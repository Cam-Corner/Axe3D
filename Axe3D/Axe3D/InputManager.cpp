#include "InputManager.h"
#include "RenderWindow.h"
#include <GLFW/glfw3.h>
#include <iostream>

namespace axe
{
	InputManager::InputManager()
	{
		SetupKeys();
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

	void InputManager::UpdateImp()
	{
		for (std::unordered_map<axe::KeyCode, axe::InputKey>::iterator
			It = _Keys.begin(); It != _Keys.end(); ++It)
		{
			It->second.Update();
		}
	}

	void InputManager::SetupKeys()
	{
		AddKeyToMap(axe::KeyCode::SPACE);
		AddKeyToMap(axe::KeyCode::APOSTROPHE);
		AddKeyToMap(axe::KeyCode::COMMA);
		AddKeyToMap(axe::KeyCode::MINUS);
		AddKeyToMap(axe::KeyCode::PERIOD);
		AddKeyToMap(axe::KeyCode::SLASH);
		AddKeyToMap(axe::KeyCode::Num0);
		AddKeyToMap(axe::KeyCode::Num1);
		AddKeyToMap(axe::KeyCode::Num2);
		AddKeyToMap(axe::KeyCode::Num3);
		AddKeyToMap(axe::KeyCode::Num4);
		AddKeyToMap(axe::KeyCode::Num5);
		AddKeyToMap(axe::KeyCode::Num6);
		AddKeyToMap(axe::KeyCode::Num7);
		AddKeyToMap(axe::KeyCode::Num8);
		AddKeyToMap(axe::KeyCode::Num9);
		AddKeyToMap(axe::KeyCode::SEMICOLON);
		AddKeyToMap(axe::KeyCode::EQUAL);
		AddKeyToMap(axe::KeyCode::A);
		AddKeyToMap(axe::KeyCode::B);
		AddKeyToMap(axe::KeyCode::C);
		AddKeyToMap(axe::KeyCode::D);
		AddKeyToMap(axe::KeyCode::E);
		AddKeyToMap(axe::KeyCode::F);
		AddKeyToMap(axe::KeyCode::G);
		AddKeyToMap(axe::KeyCode::H);
		AddKeyToMap(axe::KeyCode::I);
		AddKeyToMap(axe::KeyCode::J);
		AddKeyToMap(axe::KeyCode::K);
		AddKeyToMap(axe::KeyCode::L);
		AddKeyToMap(axe::KeyCode::M);
		AddKeyToMap(axe::KeyCode::N);
		AddKeyToMap(axe::KeyCode::O);
		AddKeyToMap(axe::KeyCode::P);
		AddKeyToMap(axe::KeyCode::Q);
		AddKeyToMap(axe::KeyCode::R);
		AddKeyToMap(axe::KeyCode::S);
		AddKeyToMap(axe::KeyCode::T);
		AddKeyToMap(axe::KeyCode::U);
		AddKeyToMap(axe::KeyCode::V);
		AddKeyToMap(axe::KeyCode::W);
		AddKeyToMap(axe::KeyCode::X);
		AddKeyToMap(axe::KeyCode::Y);
		AddKeyToMap(axe::KeyCode::Z);
		AddKeyToMap(axe::KeyCode::LEFT_BRACKET);
		AddKeyToMap(axe::KeyCode::BACKSLASH);
		AddKeyToMap(axe::KeyCode::RIGHT_BRACKET);
		AddKeyToMap(axe::KeyCode::ACCENT);
		AddKeyToMap(axe::KeyCode::ESCAPE);
		AddKeyToMap(axe::KeyCode::ENTER);
		AddKeyToMap(axe::KeyCode::TAB);
		AddKeyToMap(axe::KeyCode::BACKSPACE);
		AddKeyToMap(axe::KeyCode::INSERT);
		AddKeyToMap(axe::KeyCode::DELETE);
		AddKeyToMap(axe::KeyCode::RIGHT);
		AddKeyToMap(axe::KeyCode::LEFT);
		AddKeyToMap(axe::KeyCode::DOWN);
		AddKeyToMap(axe::KeyCode::UP);
		AddKeyToMap(axe::KeyCode::PAGE_UP);
		AddKeyToMap(axe::KeyCode::PAGE_DOWN);
		AddKeyToMap(axe::KeyCode::HOME);
		AddKeyToMap(axe::KeyCode::END);
		AddKeyToMap(axe::KeyCode::CAPS_LOCK);
		AddKeyToMap(axe::KeyCode::SCROLL_LOCK);
		AddKeyToMap(axe::KeyCode::NUM_LOCK);
		AddKeyToMap(axe::KeyCode::PRINT_SCREEN);
		AddKeyToMap(axe::KeyCode::PAUSE);
		AddKeyToMap(axe::KeyCode::F1);
		AddKeyToMap(axe::KeyCode::F2);
		AddKeyToMap(axe::KeyCode::F3);
		AddKeyToMap(axe::KeyCode::F4);
		AddKeyToMap(axe::KeyCode::F5);
		AddKeyToMap(axe::KeyCode::F6);
		AddKeyToMap(axe::KeyCode::F7);
		AddKeyToMap(axe::KeyCode::F8);
		AddKeyToMap(axe::KeyCode::F9);
		AddKeyToMap(axe::KeyCode::F10);
		AddKeyToMap(axe::KeyCode::F11);
		AddKeyToMap(axe::KeyCode::F12);
		AddKeyToMap(axe::KeyCode::F13);
		AddKeyToMap(axe::KeyCode::F14);
		AddKeyToMap(axe::KeyCode::F15);
		AddKeyToMap(axe::KeyCode::F16);
		AddKeyToMap(axe::KeyCode::F17);
		AddKeyToMap(axe::KeyCode::F18);
		AddKeyToMap(axe::KeyCode::F19);
		AddKeyToMap(axe::KeyCode::F20);
		AddKeyToMap(axe::KeyCode::F21);
		AddKeyToMap(axe::KeyCode::F22);
		AddKeyToMap(axe::KeyCode::F23);
		AddKeyToMap(axe::KeyCode::F24);
		AddKeyToMap(axe::KeyCode::F25);
		AddKeyToMap(axe::KeyCode::KP_Num0);
		AddKeyToMap(axe::KeyCode::KP_Num1);
		AddKeyToMap(axe::KeyCode::KP_Num2);
		AddKeyToMap(axe::KeyCode::KP_Num3);
		AddKeyToMap(axe::KeyCode::KP_Num4);
		AddKeyToMap(axe::KeyCode::KP_Num5);
		AddKeyToMap(axe::KeyCode::KP_Num6);
		AddKeyToMap(axe::KeyCode::KP_Num7);
		AddKeyToMap(axe::KeyCode::KP_Num8);
		AddKeyToMap(axe::KeyCode::KP_Num9);
		AddKeyToMap(axe::KeyCode::KP_DECIMAL);
		AddKeyToMap(axe::KeyCode::KP_DIVIDE);
		AddKeyToMap(axe::KeyCode::KP_MULTIPLY);
		AddKeyToMap(axe::KeyCode::KP_SUBTRACT);
		AddKeyToMap(axe::KeyCode::KP_ADD);
		AddKeyToMap(axe::KeyCode::KP_ENTER);
		AddKeyToMap(axe::KeyCode::KP_EQUAL);
		AddKeyToMap(axe::KeyCode::LEFT_SHIFT);
		AddKeyToMap(axe::KeyCode::LEFT_CONTROL);
		AddKeyToMap(axe::KeyCode::LEFT_ALT);
		AddKeyToMap(axe::KeyCode::RIGHT_SHIFT);
		AddKeyToMap(axe::KeyCode::RIGHT_CONTROL);
		AddKeyToMap(axe::KeyCode::RIGHT_ALT);
	}

	void InputManager::AddKeyToMap(axe::KeyCode Key)
	{
		_Keys[Key] = axe::InputKey(Key);
	}
}