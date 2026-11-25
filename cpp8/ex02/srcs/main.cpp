#include "../includes/header.hpp"
#include <iostream>
#include <stack>
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	mstack.push(5);
	mstack.push(17);
	list.push_back(5);
	list.push_back(17);
	std::cout << "mstack begin: " << mstack.top() << std::endl;
	std::cout << "list begin: " << list.back() << std::endl;

	mstack.pop();
	list.pop_back();
	std::cout << "mstack size: " << mstack.size() << std::endl;
	std::cout << "list size: " << list.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::list<int>::iterator l_it = list.begin();
	std::list<int>::iterator l_ite = list.end();
	++l_it;
	--l_it;

	std::cout << "MSTACK: {";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "}" << std::endl;

	std::cout << "LIST: {";
	while (l_it != l_ite)
	{
		std::cout << *l_it << " ";
		++l_it;
	}
	std::cout << "}" << std::endl;

	return 0;
}
