#include "system.h"
namespace RayEngine
{
	RayEngine::Time::Time(uint32_t init)
	{
		milliseconds = init == 0 ? SDL_GetTicks() : init;
	}

	uint32_t Time::asMilliseconds() const
	{
		return milliseconds;
	}

	double Time::asSeconds() const
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
		: name(name), w(w), h(h), isOpen(false){}
		
	
	void Window::open(int x, int y, int windowFlag)
	{
		if(!isOpen)
		{
			if(!SDL_WasInit(SDL_INIT_EVERYTHING) && SDL_Init(SDL_INIT_EVERYTHING) != 0)
				throw SDLException("Could not initialize SDL");
			windowPtr = SDL_CreateWindow(name.c_str(), x, y, w, h, windowFlag);
			renderPtr = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			isOpen = windowPtr != nullptr && renderPtr != nullptr;
			if(!isOpen)
				throw SDLException("Could not create window");
			ID = SDL_GetWindowID(windowPtr);
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

	void Window::drawBuffer(const DrawBuffer & buffer)
	{
		for (auto &line : buffer)
		{
			SDL_SetRenderDrawColor(renderPtr, line.color.r, line.color.g, line.color.b, 255);
			SDL_RenderDrawLine(renderPtr, line.start.x, line.start.y, line.end.x, line.end.y);
		}

		SDL_RenderPresent(renderPtr);
	}

	void Window::clear(const ColorRGB & color)
	{
		SDL_SetRenderDrawColor(renderPtr, color.r, color.g, color.b, 255);
	}

	Uint32 Window::getID()
	{
		return ID;
	}
	
	Window::~Window()
	{
		if(isOpen)
			close();
	}
}