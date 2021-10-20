#pragma once
#include <iostream>

namespace beak_16929 {
	const int MAX_NUMBER = 50;
	bool visited[MAX_NUMBER][MAX_NUMBER];
	std::string Tmap[MAX_NUMBER];
	int width = 0;
	int height = 0;

	bool dfs(int x, int y, int depth)
	{
		static int startX = 0;
		static int startY = 0;
		static char startCh = 0;
		static bool rtn = false;
		if (depth == 0)
		{
			startX = x;
			startY = y;
			startCh = Tmap[startY][startX];
			rtn = false;
		}
		

		const int dx[4] = { 1, -1, 0, 0 };
		const int dy[4] = { 0, 0, -1, 1 };
		
		visited[y][x] = true;
		
		for (int k = 0; k < 4; k++)
		{
			int postX = x + dx[k];
			int postY = y + dy[k];
			if ((0 <= postX && postX < width) && (0 <= postY && postY < height)
				&& visited[postY][postX] == false
				&& Tmap[postY][postX] == startCh)
			{
				dfs(postX, postY, depth + 1);
			}
			if (postX == startX && postY == startY
				&& visited[postY][postX] == true
				&& depth > 2)
			{
				rtn = true;
				return rtn;
			}
			

		}
		return rtn;
	}

	int sol_16929_main()
	{
		std::cin >> height >> width;
		for (int i = 0; i < height; i++)
		{
			std::cin >> Tmap[i];
		}
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				memset(visited, 0x00, sizeof(visited));
				if (dfs(x, y, 0))
				{
					std::cout << "Yes" << std::endl;
					return 0;				
				}
			}
		}
		std::cout << "No" << std::endl;
		return 0;
	}
}