#include "view.h"

namespace RayEngine
{
	Vector2f & View::pos()
	{
		return _pos;
	}
	Vector2f & View::dir()
	{
		return _dir;
	}
	void View::project(const Vector2 & screenSize)
	{
		for (int x = 0; x < screenSize.x; x++)
		{
			//this gives us a camera x in the FOV between -1 (far left) and 1 (far right)
			float cameraX = 2 * x / (float)screenSize.x - 1;

			//the ray direction is the sum of the direction vector and part of the plane vector
			Vector2f rayDir = { _dir.x + _plane.x * cameraX , _dir.y + _plane.y * cameraX };

			//which box of the map we're currently in
			Vector2 map = { (int)_pos.x, (int)_pos.y };
			
			//lengths from current ry position to next x or y side
			Vector2f sideDist;

			//length of a ray from one x or y side to the next
			//the deltaDist is the absolute value of 1/rayDir
			Vector2f deltaDist = { std::abs(1 / rayDir.x), std::abs(1 / rayDir.y) };

			double perpWallDist;

			bool hit = false;
			int side = 0;

			Vector2 step;

			//calculate step and initial sideDist
			if (rayDir.x < 0)
			{
				step.x = -1;
				sideDist.x = (_pos.x - map.x) * deltaDist.x;
			}
			else
			{
				step.x = 1;
				sideDist.x = (_pos.x - map.x) * deltaDist.x;
			}
			if (rayDir.y < 0)
			{
				step.y = -1;
				sideDist.y = (_pos.y - map.y) * deltaDist.y;
			}
			else
			{
				step.y = 1;
				sideDist.y = (_pos.y - map.y) * deltaDist.y;
			}

			//DDA algorithm to determine when wall hits
			while (hit == 0)
			{
				if (sideDist.x < sideDist.y)
				{
					sideDist.x += deltaDist.x;
					map.x += step.x;
					side = 0;
				}
				else
				{
					sideDist.y += deltaDist.y;
					map.y += step.y;
					side = 1;
				}

				//TODO: Check for world map hit
			}

			//calculate distance from ray to wall
			perpWallDist = side == 0 ? (map.x - _pos.x + (1 - step.x) / 2) / rayDir.x : (map.y - _pos.y + (1 - step.y) / 2) / rayDir.y;

			//calculate height of line to draw on screen
			int lineHeight = (int)(screenSize.y / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + screenSize.y / 2;
			if (drawStart < 0) drawStart = 0;
			int drawEnd = lineHeight / 2 + screenSize.y / 2;
			if (drawEnd >= screenSize.y) drawEnd = screenSize.y - 1;

			//choose wall color


		}
	}

}