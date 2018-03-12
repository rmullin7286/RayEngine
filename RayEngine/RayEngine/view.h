#ifndef RAYCAST_VIEW_H
#define RAYCAST_VIEW_H

#include "basictypes.h"
#include <cmath>
#include "world.h"
#include "system.h"

namespace RayEngine
{

	class View
	{
		Vector2<float> position;
		Vector2<float> direction;
		Vector2<float> plane;
		Vector2<float> dimensions;
		DrawBuffer buffer;

	public:
		View(float w, float h, Vector2<float> position = { 0.0, 0.0 }, Vector2<float> direction = { 0.0, 0.0 });
		DrawBuffer & calculateBuffer(const Map & map);
		void setPos(Vector2<float> position);
		void setDirection(Vector2<float> direction);
		Vector2<float> getPos() const;
		Vector2<float> getDir() const;
	};

}
#endif // !RAYCAST_VIEW_H

