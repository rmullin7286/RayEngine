#include <SDL.h>
#include "rayengine.h"
#include <cstdlib>
using namespace RayEngine;

int main(int argc, char *argv[])
{
	Window window(640, 480, "Ray Engine");
	View view(640, 480);
	Map map(10, 10);
	map.addWall(9, 9, Wall(RGB_Green));
	view.setDirection({ -0.5, -0.5 });
	window.open();
	system("pause");
	return 0;
}
