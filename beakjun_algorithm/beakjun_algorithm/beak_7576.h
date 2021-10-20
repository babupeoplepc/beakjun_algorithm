#pragma once

#include <iostream>
#include <vector>
#include <queue>


namespace beak_7576 {
	const int MAX_NUMBER = 1000;
	int tomato[MAX_NUMBER][MAX_NUMBER] = {0, };
	int tdp[MAX_NUMBER][MAX_NUMBER] = {0, };

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int n = 0;
	int m = 0;

	void printTdp()
	{
		std::cout << "==============================" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << tdp[i][j] << " ";
			}
			std::cout << std::endl;
		}
		
		std::cout << "==============================" << std::endl;
	}
	void printTomato()
	{
		std::cout << "==============================" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << tomato[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << "==============================" << std::endl;
	}

	int bfs(std::vector<std::pair<int, int>> &vec)
	{
		int rtn = 0;
		
		
		std::queue<std::pair<int, int>> q;
		for (auto val : vec)
		{
			q.push(val);
		}
		

		while (!q.empty())
		{
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int postX = curX + dx[k];
				int postY = curY + dy[k];
				int dpValue = tdp[curY][curX] + 1;
				if ((0 <= postX && postX < m) && (0 <= postY && postY < n)
					&& tomato[postY][postX] == 0
					&& (dpValue < tdp[postY][postX] || tdp[postY][postX] == 0))
				{
					tomato[postY][postX] = 1;
					
					tdp[postY][postX] = dpValue;
					
					q.push(std::make_pair(postX, postY));
					rtn = (rtn > dpValue) ? rtn : dpValue;
					//printTdp();
				}
			}
		}

		return rtn;
	}

	int sol_7576_main()
	{
		std::cin >> m >> n;
		std::vector<std::pair<int, int>> vec;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int x;
				std::cin >> x;
				tomato[i][j] = x;
				if(x == 1)
					vec.push_back(std::make_pair(j, i));
			}
		}
		
		
		int rtn = 0;
		
		bfs(vec);
			
		

		int i, j;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (tomato[i][j] == 0 )
				{
					
					std::cout << "-1" << std::endl;
					return 0;					
				}
				else
				{
					rtn = (rtn > tdp[i][j]) ? rtn : tdp[i][j];
				}
				
			}
		
		}


		std::cout << rtn << std::endl;

		return 0;
	}
}
