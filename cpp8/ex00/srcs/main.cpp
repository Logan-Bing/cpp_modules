#include "../includes/header.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <list>


int main()
{
	typedef std::vector<int>	ints_v;
	typedef std::list<int>		ints_l;
	typedef std::deque<int>		ints_d;

	int nums_tab[] = {10, 20, 30, 40, 50};
	int* first = nums_tab;
	int* last = nums_tab + sizeof(nums_tab) / sizeof(int);

	ints_v nums_v(first, last);
	ints_l nums_l(first, last);
	ints_d nums_d(first, last);

	try
	{
		std::cout << easyfind<ints_v>(nums_v, 10) << std::endl;
		std::cout << easyfind<ints_l>(nums_l, 20) << std::endl;
		std::cout << easyfind<ints_d>(nums_d, 30) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << easyfind<ints_v>(nums_v, 1) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
