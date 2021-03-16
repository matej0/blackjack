#pragma once
#include "includes.h"

namespace Utils
{
	int Random(int min, int max)
	{
		std::random_device                  Device;
		std::mt19937                        Generator(Device());
		std::uniform_int_distribution<int>    Distr(min, max);

		return Distr(Generator);
	}

	void PrintVector(std::vector<int> &vector)
	{
		for (unsigned int i = 0; i < vector.size(); i++)
		{
			if (vector.back() == vector.at(i))
			{
				std::cout << vector.at(i) << " ";
			}
			else
			{
				std::cout << vector.at(i) << ", ";
			}
		}
	}
}