#include "../includes/header.hpp"
#include <iostream>

int main()
{
	// if (argc == 2)
	// {
	// 	ScalarConverter::convert(std::string(argv[1]));
	// }
	
	char ch = 'a';
	double d = static_cast<double>(ch);

	std::cout << d << std::endl;
	return 0;
}
