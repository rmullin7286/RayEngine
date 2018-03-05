#ifndef RAYENGINE_WORLD_H
#define RAYENGINE_WORLD_H

#include "basictypes.h"
#include <vector>

namespace RayEngine
{
	class Wall
	{
		ColorRGB color;
	public:
		Wall(const ColorRGB & color);
		ColorRGB getColor() const;
		void setColor(const ColorRGB & color);
	};

	class Map
	{
		std::vector<std::vector<Wall>> internal_vector;
	public:
		Map(unsigned int x = 1, unsigned int y = 1);
		std::vector<Wall> & operator[](const unsigned int & index);
		void resize(unsigned int x = 1, unsigned int y = 1);
		Vector2<unsigned int> size();
	};
}

#endif