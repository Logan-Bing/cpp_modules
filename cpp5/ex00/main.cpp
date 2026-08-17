#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

int main()
{
	try
	{
		Bureaucrat b1("jhon", 1);
		b1.decrement();
		std::cout << b1 << std::endl;
	}
	catch(std::exception& e)
	{
		// This one not get catched
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b1("jhon", 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b1("jhon", 1);
		b1.increment();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b1("jhon", 150);
		b1.decrement();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
