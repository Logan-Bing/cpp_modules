#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

int main()
{
	try
	{
		Bureaucrat b1("jhon", 1);
		b1.increment();
	}
	catch(std::exception& e)
	{
		std::cout << "Catched !!" << std::endl;
		std::cout << e.what() << std::endl;
	}
}
