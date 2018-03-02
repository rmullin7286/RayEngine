#ifndef RAYCAST_WINDOW_H
#define RAYCAST_WINDOW_H

#include <SDL.h>
#include <string>
using std::string;

namespace RayEngine
{
	class Window
	{
	public:
		bool init(int w, int h, const string &name, int x_center=SDL_WINDOWPOS_CENTERED, int y_center=SDL_WINDOWPOS_CENTERED);
	private:
		int _h, _w;
		SDL_Window * window;
		SDL_Surface * surface;
		string _name;
	};
}

#endif
