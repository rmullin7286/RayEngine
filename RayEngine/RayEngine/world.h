#ifndef RAYENGINE_WORLD_H
#define RAYENGINE_WORLD_H

#include "basictypes.h"
#include <unordered_map>
#include <string>
#include <optional>

namespace RayEngine
{
	class Wall
	{
		ColorRGB color;
	public:
		Wall(const ColorRGB & color = { 0,0,0 });
		ColorRGB getColor() const;
		void setColor(const ColorRGB & color);
		Wall & operator=(const Wall & rhs);
	};

	class Map
	{
		std::unordered_map<unsigned int, std::unordered_map<unsigned int, Wall>> wallMap;
		Vector2<unsigned int> _size;
		// saves the index of the last wall you looked up calling "isWall".
		// This saves from having to look up twice
		Wall * lookupIndex;
	public:
		Map(unsigned int x = 1, unsigned int y = 1);
		void resize(unsigned int x = 1, unsigned int y = 1);
		Vector2<unsigned int> size() const;
		void addWall(unsigned int x, unsigned int y, const Wall & newWall);
		bool removeWall(unsigned int x, unsigned int y);
		std::optional<Wall> findWall(unsigned int x, unsigned int y) const;
	};
}

#endif