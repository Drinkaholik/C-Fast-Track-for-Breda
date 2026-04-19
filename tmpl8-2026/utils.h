#pragma once

// Global functions for use
namespace utils
{

	// Math functions //

	// Sign
	template <typename T> static int sign(T value)
	{
		return (T(0) < value) - (value < T(0)); // Uses bools being 1 or 0 to return the sign of the value
	};





};

