#ifndef RAYCAST_VIEW_H
#define RAYCAST_VIEW_H

#include "basictypes.h"
#include <cmath>
#include <vector>
#include "world.h"

namespace RayEngine
{
	class View
	{
		Vector2<float> position;
		Vector2<float> direction;
		Vector2<float> plane;
		Vector2<unsigned int> dimensions;
		std::vector<std::vector<unsigned int>> buffer;

	public:
		View(unsigned int w, unsigned int h, Vector2<float> position = { 0.0, 0.0 }, Vector2<float> direction = { 0.0, 0.0 });
		const std::vector<std::vector<unsigned int>> & calculateBuffer(const Map & map) const;
		void setPos(Vector2<float> position);
	};

}
#endif // !RAYCAST_VIEW_H

