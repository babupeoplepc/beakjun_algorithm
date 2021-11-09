#pragma once
namespace beak_13549 {
#include <iostream>
#include <vector>
#include <queue>
	const int MAX_NUMBER = 100001;
	int dp[MAX_NUMBER] = { 0, };
	
	bool visited[MAX_NUMBER] = { false, };

	int (*fp[3])(int);

	int func1(int x)
	{
		return (0 <= x + 1 && x + 1 < MAX_NUMBER) ? x + 1 : -1;
	}
	int func2(int x)
	{
		return (0 <= x - 1 && x - 1 < MAX_NUMBER) ? x - 1 : -1;
	}
	int func3(int x)
	{
		return (0 <= x * 2 && x * 2 < MAX_NUMBER) ? x * 2 : -1;
	}


	int bfs(int start, int end)
	{
		if (start == end) return 0;
		fp[0] = func1;
		fp[1] = func2;
		fp[2] = func3;

		std::queue<int> q;
		q.push(start);
		dp[start] = 0;
		while (!q.empty())
		{
			int curNode = q.front();
			q.pop();
			for (int i = 0; i < 3; i++)
			{
				int nextNode = fp[i](curNode);

				if (nextNode != -1 && !visited[nextNode])
				{
					q.push(nextNode);
					visited[nextNode] = true;
					if (i == 2)
					{
						dp[nextNode] = dp[curNode];
					
					}
					else
					{
						dp[nextNode] = dp[curNode] + 1;
					}
					
					
					
					if (nextNode == end) return dp[nextNode];
				}
			}
		}
		return 0;
	}

	int main()
	{
		int subin, bro;
		std::cin >> subin >> bro;
		std::cout << bfs(subin, bro) << std::endl;

		return 0;
	}

}