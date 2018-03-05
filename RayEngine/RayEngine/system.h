#ifndef RAYENGINE_SYSTEM_H
#define RAYENGINE_SYSTEM_H

#include <SDL.h>

namespace RayEngine
{
	class Time
	{
		uint32_t startTime;

	public:
		Time(uint32_t init = 0);
		uint32_t asMilliseconds();
		uint32_t asSeconds();
		Time operator+(const Time & rhs);
		Time operator-(const Time & rhs);
		Time & operator=(const Time & rhs);
	};

	class Delta
	{
		Time oldTime;

	public:
		Delta();
		Time getElapsedTime();
		Time restart();
	};
}

#endif