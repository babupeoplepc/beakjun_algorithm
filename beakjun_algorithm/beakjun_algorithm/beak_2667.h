#pragma once
#include <iostream>
#include <vector>
bool House_2667[25][25] = { false, };
const int MAX_NUMBER_2667 = 625;
bool visited_2667[MAX_NUMBER_2667];
std::vector<int> vec_2667[MAX_NUMBER_2667];

int ConnectedComp_2667 = 0;
int dfs_2667(int node, bool init)
{
	static int count = 0;
	if (init) count = 0;
	visited_2667[node] = true;
	count++;
	for (int i = 0; i < vec_2667[node].size(); i++)
	{
		int n = vec_2667[node][i];
		if (!visited_2667[n])
			dfs_2667(n, false);
	}
	return count;
}

int sol_2667_main()
{
	int Line;
	std::cin >> Line;

	for (int i = 0; i < Line; i++)
	{
		for (int j = 0; j < Line; j++)
		{
			char x;
			std::cin >> x;
			House_2667[i][j] = (x == '1') ? true : false ;
		}
	}

	
	int up, down, left, right;

	for (int i = 0; i < Line; i++)
	{
		for (int j = 0; j < Line; j++)
		{
			if (House_2667[i][j])
			{
				int index = i * Line + j;
				if (i - 1 >= 0)
				{
					int index_up = (i - 1) * Line + j;
					if (House_2667[i-1][j])
					{
						vec_2667[index].push_back(index_up);
					}
				}
				if (j - 1 >= 0)
				{
					int index_left = i * Line + (j-1);
					if (House_2667[i][j-1])
					{
						vec_2667[index].push_back(index_left);
					}
				}
				if (i + 1 < Line)
				{
					int index_down = (i + 1) * Line + j;
					if (House_2667[i +1][j])
					{
						vec_2667[index].push_back(index_down);
					}
				}
				if (j + 1 < Line)
				{
					int index_right = i * Line + (j + 1);
					if (House_2667[i][j + 1])
					{
						vec_2667[index].push_back(index_right);
					}
				}


			}
			
		}
	}

	std::vector<int> output;
	for (int i = 0; i < Line*Line; i++)
	{
		int x = i / Line;
		int y = i % Line;
		if (visited_2667[i] == false && House_2667[x][y] == true)
		{
			int count = dfs_2667(i, true);

			if (output.empty())
			{
				output.push_back(count);
			}
			else
			{
				auto it = output.begin();
				for (; it != output.end(); ++it)
				{
					if (*it > count)
					{
						break;
					}
				}
				output.insert(it, count);
			}
			ConnectedComp_2667++;

		}
	}
	std::cout << ConnectedComp_2667 << std::endl;
	for (int x : output)
	{
		std::cout << x << std::endl;
	}
	return 0;
}