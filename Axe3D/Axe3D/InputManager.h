#pragma once

#include <unordered_map>
#include "InputKey.h"

namespace axe
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
		///*Only returns true on the frame the key was pressed (does not account for holding the button down)
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

		static void Update() { Get().UpdateImp(); }

	private:
		void UpdateImp();
		bool GetKeyDownImp(KeyCode Key);
		bool GetKeyUpImp(KeyCode Key);
		bool GetKeyImp(KeyCode Key);

		void SetupKeys(); 
		void AddKeyToMap(axe::KeyCode Key);

		std::unordered_map<axe::KeyCode, axe::InputKey> _Keys;

	};
}

