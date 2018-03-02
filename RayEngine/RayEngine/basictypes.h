#ifndef BASICTYPES_H
#define BASICTYPES_H

namespace RayEngine
{
	//a struct for 2d vector ints
	struct Vector2
	{
		int x, y;
	};

	//a struct for 2d vector floats
	struct Vector2f
	{
		float x, y;
	};

	class DeltaTime
	{
	public:
		float elapsedTime();
		float time();

	private:
		double _oldTime, _time;
	};
}
#endif
