#ifndef RAYCAST_VIEW_H
#define RAYCAST_VIEW_H

#include "basictypes.h"
#include <cmath>

namespace RayEngine
{
	class View
	{
	public:
		Vector2f & pos();
		Vector2f & dir();
		void project(const Vector2 & screenSize);


	private:
		Vector2f _pos = { 0.0f, 0.0f }; // x and y position in 2d space
		Vector2f _dir = { 0.0f, 0.0f }; // rotation of the view
		Vector2f _plane = { 0.0f, 0.66f }; // Field of View for the camera
	};

}
#endif // !RAYCAST_VIEW_H

