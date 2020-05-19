#pragma once

#include <unordered_map>
#include "InputKey.h"
#include "InputMouseButton.h"
#include <glm/glm.hpp>

namespace Axe
{
	class InputManager
	{
	public:
		InputManager(const InputManager&) = delete;

		static InputManager& Get()
		{
			static InputManager _Input;
			return _Input;
		}		

		~InputManager() { }
	private:
		InputManager();

	public:
		///<summary>
		///*Only returns true on the frame the key was pressed (does not account for holding the key down)
		///</summary>
		static bool GetKeyDown(KeyCode Key) { return Get().GetKeyDownImp(Key); }
		///<summary>
		///*Only returns true on the frame the key was Released
		///</summary>
		static bool GetKeyUp(KeyCode Key) { return Get().GetKeyUpImp(Key); }
		///<summary>
		///*Returns true if the key is pressed
		///</summary>
		static bool GetKey(KeyCode Key) { return Get().GetKeyImp(Key); }

		///<summary>
		///*Only returns true on the frame the mouse button was pressed (does not account for holding the button down)
		///</summary>
		static bool GetButtonDown(MouseButton Button) { return Get().GetButtonDownImp(Button); }
		///<summary>
		///*Only returns true on the frame the mouse button was Released
		///</summary>
		static bool GetButtonUp(MouseButton Button) { return Get().GetButtonUpImp(Button); }
		///<summary>
		///*Returns true if the mouse button is pressed
		///</summary>
		static bool GetButton(MouseButton Button) { return Get().GetButtonImp(Button); }

		static void Update() { Get().UpdateImp(); }

		static glm::vec2 MousePosition() { return Get().MousePositionImp(); }
		static double GetMouseXOffset() { return Get().GetMouseXOffsetImp(); }
		static double GetMouseYOffset() { return Get().GetMouseYOffsetImp(); }

	private:
		void UpdateImp();
		bool GetKeyDownImp(KeyCode Key);
		bool GetKeyUpImp(KeyCode Key);
		bool GetKeyImp(KeyCode Key);

		bool GetButtonDownImp(MouseButton Button);
		bool GetButtonUpImp(MouseButton Button);
		bool GetButtonImp(MouseButton Button);

		glm::vec2 MousePositionImp();
		double GetMouseXOffsetImp();
		double GetMouseYOffsetImp();

		//Mouse Variables
		bool _DoneMouseSetup{ false };
		double _LastMouseXPos{ 0 };
		double _LastMouseYPos{ 0 };
		double _MouseXOffset{ 0 };
		double _MouseYOffset{ 0 };

		void SetupKeys(); 
		void AddKeyToMap(Axe::KeyCode Key);
		void AddMouseButtonToMap(Axe::MouseButton Button);

		std::unordered_map<Axe::KeyCode, Axe::InputKey> _Keys;
		std::unordered_map<Axe::MouseButton, Axe::InputMouseButton> _MouseButtons;
	};
}

