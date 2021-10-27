#pragma once
namespace beak_2146
{
#include <iostream>
#include <queue>
#include <vector>

	const int MAX_NUMBER = 100;
	bool originalMap[MAX_NUMBER][MAX_NUMBER];
	bool visited[MAX_NUMBER][MAX_NUMBER];
	int islandMap[MAX_NUMBER][MAX_NUMBER];
	int islandDp[MAX_NUMBER][MAX_NUMBER];

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	void printOriginalMap(int n)
	{
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << originalMap[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	void printVisited(int n)
	{
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout <<visited[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	void printMap(int n)
	{
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << islandMap[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void printDp(int n)
	{
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << islandDp[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	inline bool checkLimit(int x, int y, int n)
	{
		return ((0 <= x && x < n) && (0 <= y && y < n));
	}
	void dfs(int& x, int& y, int& iNumber, int& n)
	{
		visited[y][x] = true;
		islandMap[y][x] = iNumber;
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (checkLimit(nextX, nextY,n )
				&&	visited[nextY][nextX] == false && originalMap[nextY][nextX] == true)
			{
				dfs(nextX, nextY, iNumber, n);
			}
		}
	}
	void bfs(int x, int y, int isNumber, int n)
	{
		std::queue<std::pair<int, int>> q;
		q.push(std::make_pair(x, y));
		while (!q.empty())
		{
			std::pair<int, int> curPos = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextX = curPos.first + dx[i];
				int nextY = curPos.second + dy[i];
				if (checkLimit(nextX, nextY, n)
					&& visited[nextY][nextX] == false)
				{
					visited[nextY][nextX] = true;
					q.push(std::make_pair(nextX, nextY));
					if (islandMap[nextY][nextX] == 0)
					{
						islandDp[nextY][nextX] = islandDp[curPos.second][curPos.first] + 1;
					}
				}
			}
		}
	}

	void findConnectedComponent(int n)
	{
		int islandcount = 1;
		for (int y = 0; y < n; y++)
		{
			for (int x= 0; x < n; x++)
			{
				if (visited[y][x] == false && originalMap[y][x] == true)				
				{
					dfs(x, y, islandcount, n);
					islandcount++;
				}
			}
		}

	}

	int main()
	{
		int numberOfLine;
		std::cin >> numberOfLine;
		for (int i = 0; i < numberOfLine; i++)
		{
			for (int j = 0; j < numberOfLine; j++)
			{
				int n1;
				std::cin >> n1;
				originalMap[i][j] = n1;
			}
		}		
		findConnectedComponent(numberOfLine);
		printMap(numberOfLine);
		//printVisited(numberOfLine);

		memset(visited, 0x00, sizeof(visited));
		bfs(0, 0, 1, numberOfLine);
		printDp(numberOfLine);
		printVisited(numberOfLine);
		return 0;
	}
}