#pragma once
namespace beak_13913
{
#include <iostream>
#include <vector>
#include <queue>

	const int MAX_NUMBER = 100001;
	int dp[MAX_NUMBER] = { 0, };
	int ParentNode[MAX_NUMBER] = { 0, };
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


	int bfs(int start, int end )
	{
		if (start == end) return 0;
		//if (start > end)	return start - end;
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
					dp[nextNode] = dp[curNode] + 1;
					ParentNode[nextNode] = curNode;
					if (nextNode == end) return dp[nextNode];
				}
			}
		}
		return 0;
	}

	int main()
	{

		int subin;
		int bro;

		std::cin >> subin >> bro;
		int fastTime = bfs(subin, bro);
		int node = bro;
		std::vector<int> vec;

		vec.push_back(bro);
		
		for (int i = 0; i < fastTime; i++)
		{
			node = ParentNode[node];
			vec.push_back(node);
		}
		std::cout << fastTime << std::endl;
		for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;


		return 0;
	}
}