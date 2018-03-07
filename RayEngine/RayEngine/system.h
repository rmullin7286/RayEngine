#ifndef RAYENGINE_SYSTEM_H
#define RAYENGINE_SYSTEM_H

#include <SDL.h>
#include <string>

namespace RayEngine
{
	class Time
	{
		uint32_t milliseconds;

	public:
		Time(uint32_t init=0);
		uint32_t asMilliseconds();
		double asSeconds();
		Time operator-(const Time & rhs);
		Time & operator=(const Time & rhs);
	};

	class Delta
	{
		Time oldTime;

	public:
		Delta() = default;
		Time getElapsedTime();
		Time restart();
	};

	class Window
	{
		unsigned int w, h;
		std::string name;
		bool isOpen;

	public:
		Window(unsigned int w, unsigned int h, const std::string & name, bool open=true);
		bool open();
		bool close();
	};
}

#endif