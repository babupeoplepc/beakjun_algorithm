#pragma once
#include <iostream>
#include <vector>

namespace beak_2178 {
	
	const int MAX_X = 100;
	const int MAX_Y = 100;
	const int MAX_NUMBER = 100 * 100;
	std::vector<int> vec[MAX_NUMBER];
	bool visited[MAX_NUMBER] = { false, };
	
	int dfs(int node, int target)
	{
		static int min = target;
		static int cur = 0;

		visited[node] = true;
		cur++;

		if (node == target)
		{
			min = (min < cur) ? min : cur;
			visited[node] = false;
			cur--;
			return min;
		}

		for (int i = 0; i < vec[node].size(); i++)
		{
			int n = vec[node][i];
			if (!visited[n])
			{
				dfs(n, target);
			}
		}
		visited[node] = false;
		cur--;
		return min;
	}


	int sol_2178_main()
	{
		int n, m;
		std::cin >> n >> m;

		bool land[MAX_X][MAX_Y] = {false, };
		

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char x;
				std::cin >> x;
				if (x == '1')
				{
					land[i][j] = true;
				}
			}
		}

		for (int i = 0; i < n * m; i++)
		{
			int x = i % m;
			int y = i / m;
			if (!land[y][x]) continue;

			if (x - 1 >= 0)
			{
				if (land[y][x - 1])
				{
					int z = (y)*m + (x - 1);
					vec[i].push_back(z);
				}
			}
			if (x + 1 < m)
			{
				if (land[y][x + 1])
				{
					int z = (y)*m + (x + 1);
					vec[i].push_back(z);
				}
			}
			if (y - 1 >= 0)
			{
				if (land[y - 1][x])
				{
					int z = (y - 1)*m + (x);
					vec[i].push_back(z);
				}
			}
			if (y + 1 < n)
			{
				if (land[y + 1][x])
				{
					int z = (y + 1) * m + (x);
					vec[i].push_back(z);
				}
			}
		}


		std::cout << dfs(0, n * m-1) << std::endl;
		
		return 0;
	}
}
