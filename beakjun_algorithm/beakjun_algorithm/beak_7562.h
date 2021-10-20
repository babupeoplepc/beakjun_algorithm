#pragma once
#include <queue>
#include <iostream>
#include <vector>
#include <memory.h>

namespace beak_7562 {

	const int MAX_NUMBER = 300;
	int cdp[MAX_NUMBER][MAX_NUMBER] = { 0, };
	int dx[8] = { 1,  2, 2, 1, -1, -2, -2, -1 };
	int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int line = 0;
	void printCdp()
	{
		std::cout << "==============================" << std::endl;
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < line; j++)
			{
				std::cout << cdp[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << "==============================" << std::endl;
	}

	int bfs(std::pair<int, int>& start, std::pair<int, int>& end)
	{
		if (start == end)
			return 0;
		std::queue<std::pair<int,int>> q;
		q.push(start);
		while (!q.empty())
		{
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();
			for (int k = 0; k < 8; k++)
			{
				int postX = curX + dx[k];
				int postY = curY + dy[k];
				if ((0 <= postX && postX < line) && (0 <= postY && postY < line)
					&& cdp[postY][postX] == 0)
				{
					cdp[postY][postX] = cdp[curY][curX] + 1;
					q.push(std::make_pair(postX, postY));
					if (postY == end.second && postX == end.first)
					{
						return cdp[postY][postX];
					}
				}

			}
		}
		return 0;


	}

	int sol_7562_main()
	{
		
		int numberOfCase = 0;
		std::cin >> numberOfCase;

		std::vector<int> output;
		for (int i = 0; i < numberOfCase; i++)
		{
			memset(cdp, 0x00, sizeof(cdp));

			std::cin >> line;
			std::pair<int, int> start, end;
			std::cin >> start.first >> start.second;
			std::cin >> end.first >> end.second;

			

			output.push_back(bfs(start, end));
			
			
		}
		for (int x : output)
		{
			std::cout << x << std::endl;
		}
		return 0;
	}
}