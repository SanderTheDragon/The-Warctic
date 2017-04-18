#include "utils/Math.hpp"

#include "Config.hpp"

uint Math::CalculateWinWidth(uint aspect, uint height)
{
	switch (aspect)
	{
		default:
		case ASPECT_16_9:
			return (height / 9) * 16;
			break;
		case ASPECT_16_10:
			return (height / 10) * 16;
			break;
		case ASPECT_4_3:
			return (height / 3) * 4;
			break;
	}
}
