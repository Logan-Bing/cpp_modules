#include "../includes/header.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main()
{
	int seed_tab[] = {21, 15, 20, 25, 30};
	int size = sizeof(seed_tab) / sizeof(int);
	ints_v seed(seed_tab, seed_tab + size);

	Span s(size);

	try
	{
		s.addNumbers<ints_v>(seed);
		std::cout << s.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
