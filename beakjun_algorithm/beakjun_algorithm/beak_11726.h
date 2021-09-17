#pragma once
#include <iostream>

int sol_11726_main()
{
	int number;
	std::cin >> number;
	if (number <= 1)
	{
		std::cout << '1' << std::endl;;
	}
	else
	{
		int* num_data = new int[number + 1];
		num_data[1] = 1;
		num_data[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			num_data[i] =( num_data[i - 1] + num_data[i - 2]) % 10007;
		}
		std::cout << num_data[number] << std::endl;

		delete[] num_data;
	}
	return 0;
	
}