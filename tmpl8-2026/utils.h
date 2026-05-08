#pragma once


// Global functions for use
namespace utils
{

	// Math functions //

	// Sign - taken from StackOverflow
	template <typename T> static int sign(T value)
	{
		return (T(0) < value) - (value < T(0)); // Uses bools being 1 or 0 to return the sign of the value
	};

	// Returns distance between 2 positions
	template <typename T> static T distance(T x1, T y1, T x2, T y2)
	{
		T xDistance = abs(x1 - x2);
		T yDistance = abs(y1 - y2);

		return abs(sqrt((xDistance * xDistance) + (yDistance * yDistance)));

	}

	


};

