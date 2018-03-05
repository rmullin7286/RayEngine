#include "world.h"

namespace RayEngine
{
	Wall::Wall(const ColorRGB & color)
	{
		this->color = color;
	}

	ColorRGB Wall::getColor()
	{
		return color;
	}

	void Wall::setColor(const ColorRGB & color)
	{
		this->color = color;
	}
}