#pragma once
#include <iostream>
#include <vector>
#include <queue>

namespace beak_2178_DFS {
	
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
namespace beak_2178_BFS
{
	bool visited[100][100] = { false, };
	int n, m;
	std::string arr[100];
	int check[100][100] = { 0, };

	void bfs(int i, int j)
	{
		visited[i][j] = true;
		std::queue<std::pair<int, int>> q;
		q.push(std::make_pair(i, j));
		
		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { -1,0,1,0 };


		while (!q.empty())
		{
			
			int x = q.front().second;
			int y = q.front().first;

			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int newX = x + dx[k];
				int newY = y + dy[k];
				if ((0 <= newX && newX < m) && (0 <= newY && newY < n)
					&& (visited[newY][newX] == false)
					&& (arr[newY][newX] == '1')
					&& check[newY][newX] == 0)
				{
					check[newY][newX] = check[y][x] + 1;
					visited[newY][newX] = true;
					q.push(std::make_pair(newY, newX));

				}
			}
		}
	}


	int sol_2178_main()
	{
		
		std::cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			std::cin >> arr[i];
		}

		bfs(0, 0);
		std::cout << (check[n - 1][m - 1]) + 1 << std::endl;
		return 0;
	}
}