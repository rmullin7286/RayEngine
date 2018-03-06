#include "view.h"

namespace RayEngine
{
	RayEngine::View::View(unsigned int w, unsigned int h, Vector2<float> position, Vector2<float> direction) : buffer(w, std::vector<unsigned int>(h))
	{
		dimensions.x = w;
		dimensions.y = h;
		this->position = position;
		this->direction = direction;
	}

	const std::vector<std::vector<unsigned int>>& RayEngine::View::calculateBuffer(const Map & map) const
	{
		//The algorithm loops through every vertical line of pixels in the view
		for (int x = 0; x < dimensions.x; x++)
		{
			
		}
	}
}