#include "world.h"

namespace RayEngine
{
	Wall::Wall(const ColorRGB & color)
	{
		this->color = color;
	}

	ColorRGB Wall::getColor() const
	{
		return color;
	}

	void Wall::setColor(const ColorRGB & color)
	{
		this->color = color;
	}

	Wall & Wall::operator=(const Wall & rhs)
	{
		color = rhs.color;
		return *this;
	}

	Map::Map(unsigned int x, unsigned int y)
	{
		_size.x = x;
		_size.y = y;
	}

	void Map::resize(unsigned int x, unsigned int y)
	{
		_size.x = x;
		_size.y = y;
	}

	Vector2<unsigned int> Map::size() const
	{
		return _size;
	}

	void Map::addWall(unsigned int x, unsigned int y, const Wall & newWall)
	{
		wallMap[x][y] = newWall;
	}

	bool Map::removeWall(unsigned int x, unsigned int y)
	{
		auto wallX = wallMap.find(x);
		if (wallX == wallMap.end())
			return false;
		auto wallY = wallX->second.find(y);
		if (wallY == wallX->second.end())
			return false;
		wallX->second.erase(wallY);
		if (wallX->second.size() == 0)
			wallMap.erase(wallX);
		return true;
	}

	std::optional<Wall> Map::findWall(unsigned int x, unsigned int y) const
	{
		auto i = wallMap.find(x);
		if (i == wallMap.end())
			return {};
		auto j = i->second.find(y);
		if (j == i->second.end())
			return {};
		return {j->second};
	}
}
