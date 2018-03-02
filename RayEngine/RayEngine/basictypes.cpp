#include "basictypes.h"

namespace RayEngine
{
	float DeltaTime::elapsedTime()
	{
		return _oldTime - _time;
	}

	float DeltaTime::time()
	{
		return _time;
	}
}
