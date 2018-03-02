#include "window.h"
namespace RayEngine
{
	bool Window::init(int w, int h, const string &name, int x_center, int y_center)
	{
		_h = h;
		_w = w;
		_name = name;
		if (!SDL_WasInit(SDL_INIT_EVERYTHING))
			if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
				return false;
		window = SDL_CreateWindow(name.c_str(), x_center, y_center, w, h, SDL_WINDOW_SHOWN);
		if (!window)
			return false;
		surface = SDL_GetWindowSurface(window);
		return true;
	}
}
