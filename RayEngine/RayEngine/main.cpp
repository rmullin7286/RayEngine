#include <SDL.h>
#include "rayengine.h"
using namespace RayEngine;

int main(int argc, char *argv[])
{
	Window window(640, 480, "Ray Engine");
	View view(640, 480);
	Map map(10, 10);
	map.addWall(9, 9, Wall(RGB_Green));
	view.setDirection({ -1.0, -1.0 });
	window.open();
}
