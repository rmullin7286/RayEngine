#ifndef RAYENGINE_EVENTS_H
#define RAYENGINE_EVENTS_H

#include <queue>
#include <SDL.h>

namespace RayEngine
{
	/*union Event
	{
		enum class Type : Uint8
		{
			WINDOW,
			KEY
		};

		enum class WindowEventID : Uint32
		{
			CLOSE
		};

		enum class KeyState : Uint16
		{
			KEY_PRESSED,
			KEY_RELEASED
		};

		enum class Key : Uint16
		{
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			Num0,
			Num1,
			Num2,
			Num3,
			Num4,
			Num5,
			Num6,
			Num7,
			Num8,
			Num9,
			Escape,
			LControl,
			LShift,
			LAlt,
			LSystem,
			RControl,
			RShift,
			RAlt,
			RSystem,
			Menu,
			LBracket,
			RBracket,
			SemiColon,
			Comma,
			Period,
			Quote,
			Slash,
			BackSlash,
			Tilde,
			Equal,
			Dash,
			Space,
			Return,
			BackSpace,
			Tab,
			PageUp,
			PageDown,
			End,
			Home,
			Insert,
			Delete,
			Add,
			Subtract,
			Multiply,
			Divide,
			Left,
			Right,
			Up,
			Down,
			Numpad0,
			Numpad1,
			Numpad2,
			Numpad3,
			Numpad4,
			Numpad5,
			Numpad6,
			Numpad7,
			Numpad8,
			Numpad9,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			F13,
			F14,
			F15,
			Pause
		};

		struct WindowEvent
		{
			Uint32 windowID;
			Type type;
			WindowEventID eventID;
		};


		struct KeyEvent
		{
			Uint32 windowID;
			Type type;
			KeyState state;
			Key key;
		};

		WindowEvent windowEvent;
		KeyEvent keyEvent;
	};*/

	class EventQueue : private std::queue<SDL_Event>
	{
	public:
		void pollEvents();
		using std::queue<SDL_Event>::empty;
		using std::queue<SDL_Event>::size;
		using std::queue<SDL_Event>::front;
		using std::queue<SDL_Event>::back;
		using std::queue<SDL_Event>::push;
		using std::queue<SDL_Event>::emplace;
		using std::queue<SDL_Event>::pop;
		using std::queue<SDL_Event>::swap;
	};
}

#endif