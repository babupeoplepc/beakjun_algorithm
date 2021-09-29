#pragma once
#include <iostream>
#include <vector>

struct node {
	char left;
	char right;
};
std::vector<node> v(26);

void inOrder(char node)
{
	if (node == '.') return;
	inOrder(v[node].left);
	std::cout << node;
	inOrder(v[node].right);
}

void preOrder(char node)
{
	if (node == '.') return;

	std::cout << node;
	preOrder(v[node].left);
	preOrder(v[node].right);
}

void postOrder(char node)
{
	if (node == '.') return;

	
	postOrder(v[node].left);
	postOrder(v[node].right);
	std::cout << node;
}


int sol_1991_main()
{
	int number;
	std::cin >> number;
	char rt, l, r;

	for (int i = 0; i < number; i++)
	{
		std::cin >> rt >> l >> r;
		v[rt].left = l;
		v[rt].right = r;
	}


	preOrder('A');
	std::cout << std::endl;
	inOrder('A');
	std::cout << std::endl;
	postOrder('A');
	return 0;
}