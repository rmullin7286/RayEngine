#include "events.h"

void RayEngine::EventQueue::pollEvents()
{
	SDL_Event e;
	//polls for SDL events and converts them to RayEngine events
	/*while(SDL_PollEvent(&event) != 0)
		switch (event.type)
		{
		case SDL_QUIT: Event e;
			e.windowEvent.windowID = event.window.windowID;
			e.windowEvent.type = Event::Type::WINDOW;
			e.windowEvent.eventID = Event::WindowEventID::CLOSE;
			this->push(std::move(e));
			break;

		}*/

	while (SDL_PollEvent(&e) != 0)
		this->push(std::move(e));

}
