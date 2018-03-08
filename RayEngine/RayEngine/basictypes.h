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
			return *this;
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

	//some preset colors
	static const ColorRGB RGB_Black = { 0, 0, 0 };
	static const ColorRGB RGB_Red = { 255, 0, 0 };
	static const ColorRGB RGB_Green = { 0, 255, 0 };
	static const ColorRGB RGB_Blue = { 0, 0, 255 };
	static const ColorRGB RGB_Cyan = { 0, 255, 255 };
	static const ColorRGB RGB_Magenta = { 255, 0, 255 };
	static const ColorRGB RGB_Yellow = {255, 255, 0 };
	static const ColorRGB RGB_White = {255, 255, 255};
	static const ColorRGB RGB_Gray = {128, 128, 128};
	static const ColorRGB RGB_Grey = {192, 192, 192};
	static const ColorRGB RGB_Maroon = {128, 0, 0};
	static const ColorRGB RGB_Darkgreen = {0, 128, 0};
	static const ColorRGB RGB_Navy = {0, 0, 128};
	static const ColorRGB RGB_Teal = {0, 128, 128};
	static const ColorRGB RGB_Purple = {128, 0, 128};
	static const ColorRGB RGB_Olive = {128, 128, 0};

	struct Line
	{
		int start, end;
		ColorRGB color;
	};
}
#endif
