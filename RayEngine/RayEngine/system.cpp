#include "system.h"
namespace RayEngine
{
	RayEngine::Time::Time(uint32_t init)
	{
		milliseconds = init == 0 ? SDL_GetTicks() : init;
	}

	uint32_t Time::asMilliseconds()
	{
		return milliseconds;
	}

	double Time::asSeconds()
	{
		return (double)milliseconds / 1000.0;
	}

	Time Time::operator-(const Time & rhs)
	{
		return Time(milliseconds - rhs.milliseconds);
	}

	Time & Time::operator=(const Time & rhs)
	{
		this->milliseconds = rhs.milliseconds;
		return *this;
	}

	Time Delta::getElapsedTime()
	{
		return Time() - oldTime;
	}

	Time Delta::restart()
	{
		Time newTime;
		Time deltaTime = newTime - oldTime;
		oldTime = newTime;
		return deltaTime;
	}

	Window::Window(unsigned int w, unsigned int h, const std::string & name)
		: name(name), w(w), h(h){}
		
	
	void Window::open(int x, int y, int windowFlag)
	{
		if(!isOpen)
		{
			if(!SDL_WasInit(SDL_INIT_EVERYTHING) && !SDL_Init(SDL_INIT_EVERYTHING))
				throw SDLException("Could not initialize SDL");
			windowPtr = SDL_CreateWindow(name.c_str(), x, y, w, h, windowFlag);
			isOpen = windowPtr != nullptr;
			if(!isOpen)
				throw SDLException("Could not create window");
		}
	}
	
	void Window::close()
	{
		if(isOpen)
		{
			SDL_DestroyWindow(windowPtr);
			isOpen = false;
		}
	}
	
	Window::~Window()
	{
		if(isOpen)
			close();
	}
}