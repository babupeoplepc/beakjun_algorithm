#pragma once
#include <iostream>
#include <vector>
const int MAX_NUMBER_4963 = 2500;
const int NUMBER_4963 = 50;

std::vector<int> vec_4963[MAX_NUMBER_4963];

bool visited_4963[MAX_NUMBER_4963];


void dfs_4963(int node)
{
	visited_4963[node] = true;
	for (int i = 0; i < vec_4963[node].size(); i++)
	{
		int n = vec_4963[node][i];
		if (!visited_4963[n])
			dfs_4963(n);
	}
	
}
int sol_4963_main()
{

	std::vector<int> output;
	while (true)
	{
		int w, h;
		std::cin >> w >> h;
		if (w == 0 && h == 0)
			break;


		bool land_4963[NUMBER_4963][NUMBER_4963] = { false, };

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int x;
				std::cin >> x;
				if (x == 1)
				{
					land_4963[i][j] = true;
				}
			}
		}


		for (int i = 0; i < w * h; i++)
		{
			int x = i % w;
			int y = i / w;
			int z = 0;
			if (!land_4963[y][x]) continue;

			if (x - 1 >= 0 && y - 1 >= 0)
			{
				if (land_4963[y - 1][x - 1])	// left-up
				{
					z = (y - 1) * w + (x - 1);
					vec_4963[i].push_back(z);
				}
			}
			if (y - 1 >= 0)
			{
				if (land_4963[y - 1][x])	// up
				{
					z = (y - 1) * w + (x);
					vec_4963[i].push_back(z);
				}
			}
			if (x - 1 >= 0)
			{
				if (land_4963[y][x - 1])	// left
				{
					z = (y)*w + (x - 1);
					vec_4963[i].push_back(z);
				}
			}
			if (x + 1 < w)
			{

				if (land_4963[y][x + 1])	// right
				{
					z = (y)*w + (x + 1);
					vec_4963[i].push_back(z);
				}
			}

			if (x + 1 < w && y + 1 < h)
			{
				if (land_4963[y + 1][x + 1])	// right-down
				{
					z = (y + 1) * w + (x + 1);
					vec_4963[i].push_back(z);
				}
			}
			if ( y + 1 < h)
			{
				if (land_4963[y + 1][x])	// down
				{
					z = (y + 1) * w + (x);
					vec_4963[i].push_back(z);
				}
			}
			if (x + 1 < w && y - 1 >= 0)	// right-up
			{
				if (land_4963[y - 1][x + 1])	
				{
					z = (y - 1) * w + (x + 1);
					vec_4963[i].push_back(z);
				}
				
			}
			if (x - 1 >= 0 && y + 1 < h)	// left-down
			{
				if (land_4963[y + 1][x - 1])	 
				{
					z = (y + 1) * w + (x - 1);
					vec_4963[i].push_back(z);
				}
			}
		}



		int iland_count = 0;
		for (int i = 0; i < w * h; i++)
		{
			if (land_4963[i/w][i%w] == true && visited_4963[i] == false)
			{
				dfs_4963(i);
				iland_count++;
			}
		}
		output.push_back(iland_count);

		std::fill(visited_4963, visited_4963 + MAX_NUMBER_4963, false);
		
		
		for (int i = 0; i < w * h; i++)
		{
			vec_4963[i].clear();
		}
	}

	for (int x : output)
	{
		std::cout << x << std::endl;
	}
	return 0;
}