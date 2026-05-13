#pragma once

#include "template.h"


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
	// Accepts both float and int
	template <typename T> static float distance(T x1, T y1, T x2, T y2)
	{
		T xDistance = abs(x1 - x2);
		T yDistance = abs(y1 - y2);

		return abs(sqrt((xDistance * xDistance) + (yDistance * yDistance))); // Finding hypotenuse
	}


	// Returns a value between -range and range
	inline float random_range(float range)
	{
		// Bit of a hacky way to get a random range but i think it works?
		float r = Rand(2 * range);

		if (r > range)
		{
			r -= range;
			r *= -1;
		}
		return r;
	}





	// I dont think this is gonna work
	template <typename T> class generic_array
	{
	public:


		generic_array(int size) : size(size)
		{
			items = new T[size];
		}

		T* get(int i)
		{
			if (i >= size) return nullptr;
			return items[i];
		}

		void set(int i, T item)
		{
			if (i >= size) return;
			items[i] = item;
		}

		int get_size()
		{
			return size;
		}


	private:
		T* items;
		int size;

	};


};

