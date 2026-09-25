#include "../includes/header.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return 0;
	}

	std::cout << "Need one argument" << std::endl;
	return 1;
}
