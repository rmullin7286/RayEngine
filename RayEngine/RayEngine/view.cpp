#include "view.h"

namespace RayEngine
{
	RayEngine::View::View(float w, float h, Vector2<float> position, Vector2<float> direction)
	{
		dimensions.x = w;
		dimensions.y = h;
		this->position = position;
		this->direction = direction;
		plane.x = 0.0f;
		plane.y = 0.66f;
	}

	DrawBuffer & RayEngine::View::calculateBuffer(const Map & map)
	{
		//The algorithm loops through every vertical line of pixels in the view
		for (int x = 0; x < dimensions.x; x++)
		{	
			//this will be used to store walls returned from map.findWall()
			std::optional<Wall> wall;

			//finds an x coordinate for the ray between -1 (left) and 1 (right)
			float cameraX = 2 * x / dimensions.x - 1;
			Vector2<float> rayDir = {direction.x + plane.x * cameraX, direction.y + plane.y * cameraX};

			//current space on the map grid
			Vector2<int> currentPosition = { position.x, position.y };

			//length of ray from current position to next position
			Vector2<float> sideDistances;

			//length of ray from one x or y to the next
			Vector2<float> delta = { std::abs(1 / rayDir.x), std::abs(1 / rayDir.y) };
			float perpWallDist;

			bool hit = false;

			//0 if x side wall, 1 if y
			int side;

			Vector2<int> step;

			//calculate step and initial sideDist
			if (rayDir.x < 0)
			{
				step.x = -1;
				sideDistances.x = (position.x - currentPosition.x) * delta.x;
			}
			else
			{
				step.x = 1;
				sideDistances.x = (currentPosition.x + 1.0f - position.x) * delta.x;
			}
			if (rayDir.y < 0)
			{
				step.y = -1;
				sideDistances.y = (position.y - currentPosition.y) * delta.y;
			}
			else
			{
				step.y = 1;
				sideDistances.y = (currentPosition.y + 1.0f - position.y) * delta.y;
			}

			//perform DDA algorithm
			auto bounds = map.size();
			while (!hit && currentPosition.x <= bounds.x && currentPosition.y <= bounds.y)
			{
				if (sideDistances.x < sideDistances.y)
				{
					sideDistances.x += delta.x;
					currentPosition.x += step.x;
					side = 0;
				}
				else
				{
					sideDistances.y += delta.y;
					currentPosition.y += step.y;
					side = 1;
				}
				wall = map.findWall(currentPosition.x, currentPosition.y);
				//check if ray has hit wall
				if (wall)
					hit = true;
			}

			if (hit)
			{
				if (side == 0)
					perpWallDist = (currentPosition.x - position.x + (1 - step.x) / 2) / rayDir.x;
				else
					perpWallDist = (currentPosition.y - position.y + (1 - step.y) / 2) / rayDir.y;

				//height of line to draw on screen
				int lineHeight = (int)(dimensions.y / perpWallDist);

				//calculate lowest and highest pixels
				int drawStart = (int)(-lineHeight / 2 + dimensions.y / 2);
				if (drawStart < 0) drawStart = 0;
				int drawEnd = (int)(lineHeight / 2 + dimensions.y / 2);
				if (drawEnd >= dimensions.y) drawEnd = (int)dimensions.y - 1;
				
				Vector2<int> drawStartVec = { x, drawStart }, drawEndVec = {x, drawEnd};

				ColorRGB color = wall.value().getColor();
				if (side == 1)
					color = color / 2;
				buffer.push_back({ drawStartVec, drawEndVec, color});
			}
		}

		return buffer;
	}
	void View::setPos(Vector2<float> position)
	{
		this->position = position;
	}
	void View::setDirection(Vector2<float> direction)
	{
		this->direction = direction;
		//The plane is always perpendicular to the view
		this->plane.x = direction.y;
		this->plane.y = -direction.x * 0.66;
	}
	Vector2<float> View::getPos() const
	{
		return position;
	}
	Vector2<float> View::getDir() const
	{
		return direction;
	}
}