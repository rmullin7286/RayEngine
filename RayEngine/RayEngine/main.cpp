#include <SDL.h>
#include "window.h"
using RayEngine::Window;

int main(int argc, char *argv[])
{
	Window window;
	window.init(640, 480, "window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	while(1)
	{ }
	return 0;
}
