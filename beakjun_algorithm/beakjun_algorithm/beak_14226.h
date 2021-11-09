#pragma once
namespace beak_14226 {
#include <iostream>
#include <vector>
#include <queue>
	struct component {
		int dis;
		int clip;
		int time;
	};
	const int MAX_NUMBER = 1000+1;
	bool visited[MAX_NUMBER][MAX_NUMBER] = { 0, };
	
	int bfs(int end)
	{
		std::queue<component> q;
		component start;
		start.dis = 1;
		start.clip = 0;
		start.time = 0;
		q.push(start);
		visited[start.dis][start.clip] = true;
		while (!q.empty())
		{
			component curNode = q.front();
			q.pop();
			if (curNode.dis == end) return curNode.time;
			
			if (curNode.dis < MAX_NUMBER &&
				!visited[curNode.dis][curNode.dis])	// 클립보드로 복사
			{
				visited[curNode.dis][curNode.dis] = true;
				component newNode;
				newNode.dis = curNode.dis;
				newNode.clip = curNode.dis;
				newNode.time = curNode.time + 1;
				q.push(newNode);
			}
			if (curNode.dis + curNode.clip < MAX_NUMBER &&
				!visited[curNode.dis + curNode.clip][curNode.clip])	// 붙여넣기
			{
				visited[curNode.dis + curNode.clip][0] = true;;
				component newNode;
				newNode.dis = curNode.dis + curNode.clip;
				newNode.clip = curNode.clip;
				newNode.time = curNode.time + 1;
				q.push(newNode);
			}
			if (curNode.dis - 1 >= 0  &&
				!visited[curNode.dis - 1][curNode.clip])
			{
				visited[curNode.dis - 1][curNode.clip] = true;
				component newNode;
				newNode.dis = curNode.dis - 1;
				newNode.clip = curNode.clip;
				newNode.time = curNode.time + 1;
				q.push(newNode);
			}
	
		}
		
		
		return 0;
	}
	
	int main()
	{
		int number;
		std::cin >> number;
		std::cout << bfs(number) << std::endl;
		return 0;
	}
}