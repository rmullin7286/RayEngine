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

	Window::Window(unsigned int w, unsigned int h, const std::string & name, bool open=true)
		: name(name), w(w), h(h)
	{
		if (open)
		{
			if (!SDL_WasInit(SDL_INIT_EVERYTHING))
				isOpen = SDL_Init(SDL_INIT_EVERYTHING) < 0;
		}
	}

}