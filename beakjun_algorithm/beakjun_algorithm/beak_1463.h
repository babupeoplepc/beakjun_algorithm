#pragma once
#include <iostream>

#define val_min(a,b) (a < b) ? a : b;

int sol_1463_main()
{
	int number;
	std::cin >> number;
	if (number <= 1)
	{
		std::cout << '0' << std::endl;
	}
	else if (number <= 3)
	{
		std::cout << '1' << std::endl;
	}
	else
	{
		int* num_data = new int[number+1];
		std::fill(num_data, num_data + number + 1, 0x00);
		for (int i = 2; i <= number; i++)
		{
			num_data[i] = num_data[i - 1] + 1;
			if (i % 2 == 0)
			{
				num_data[i] = val_min(num_data[i], num_data[i / 2] + 1);
			}
			if (i % 3 == 0)
			{
				num_data[i] = val_min(num_data[i], num_data[i / 3] + 1);
			}
		}
		for (int i = 0; i < number; i++)
		{
			//std::cout << "[ " << i << " ] = " << num_data[i] << std::endl;
		}
		std::cout << num_data[number] << std::endl;
		delete[] num_data;
	}

	return 0;
}
