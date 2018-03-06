#ifndef BASICTYPES_H
#define BASICTYPES_H

#include <cstdint>

namespace RayEngine
{
	//A basic struct for 2d vectors
	template <typename T>
	struct Vector2
	{
		T x, y;
		Vector2<T> & operator=(Vector2<T> &rhs)
		{
			x = rhs.x;
			y = rhs.y;
		}
	};

	//A basic struct for RGB color
	struct ColorRGB
	{
		uint8_t r, g, b;
		ColorRGB& operator=(const ColorRGB& color)
		{
			r = color.r;
			g = color.g;
			b = color.b;
			return *this;
		}
	};
}
#endif
