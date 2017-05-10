#ifndef MATH_HPP_
#define MATH_HPP_

#include "misc/Types.hpp"

class Math
{
public:
	static uint CalculateWinWidth(uint aspect, uint height); //Calculate the width of the window with given aspect ratio and height
	static uint CalculateMinWinWidth(uint aspect) { return CalculateWinWidth(aspect, 480); }
};

#endif
