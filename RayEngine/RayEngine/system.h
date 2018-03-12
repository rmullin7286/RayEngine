#ifndef RAYENGINE_SYSTEM_H
#define RAYENGINE_SYSTEM_H

#include <SDL.h>
#include <string>
#include <exception>
#include <list>
#include "basictypes.h"

namespace RayEngine
{
	typedef std::list<Line> DrawBuffer;

	class Time
	{
		uint32_t milliseconds;
	public:
		Time(uint32_t init=0);
		uint32_t asMilliseconds() const;
		double asSeconds() const;
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
	
	class SDLException : public std::exception
	{
		std::string _what;
	public:
		SDLException(const std::string & message) : _what(message){};
		const char * what() const noexcept { return _what.c_str(); }
	};
	
	class Window
	{
		unsigned int w, h;
		std::string name;
		bool isOpen;
		SDL_Window * windowPtr;
		SDL_Renderer * renderPtr;
		Uint32 ID;

	public:
		Window(unsigned int w, unsigned int h, const std::string & name);
		~Window();
		void open(int x=SDL_WINDOWPOS_CENTERED, int y=SDL_WINDOWPOS_CENTERED, int windowFlag=SDL_WINDOW_SHOWN);
		void close();
		void drawBuffer(const DrawBuffer & buffer);
		void clear(const ColorRGB & color = RGB_Black);
		Uint32 getID();
	};
}

#endif