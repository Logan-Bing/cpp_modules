#include "../includes/header.hpp"
#include <iostream>

#define SIZE 3

template <typename T>
void printElement(const T e)
{
	std::cout << e << std::endl;
}

void	root(int& x)
{
	x *= x;
}

int main()
{
	int nums[SIZE] = {2, 3, 10};
	std::string tab[SIZE] = {"hello", "world", "bonjour"};

	iter(nums, SIZE, ::root);
	iter(nums, SIZE, ::printElement<int>);
	iter(tab, SIZE, ::printElement<std::string>);

	return 0;
}
