#include "../includes/header.hpp"
#include <iostream>
#include <stack>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	return 0;
}
