#include "../includes/header.hpp"
#include <iostream>

int main()
{
	std::cout << "====== VALID TEST ======" << std::endl;
	{
		std::cout << std::endl;
		Bureaucrat b1("Jhon", 1);
		PresidentialPardonForm f1("Bob");
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << std::endl;
	}
	std::cout << "====== NOT SIGNED TEST ======" << std::endl;
	{
		std::cout << std::endl;
		Bureaucrat b1("Jhon", 1);
		PresidentialPardonForm f1("Bob");
		b1.executeForm(f1);
		std::cout << std::endl;
	}
	std::cout << "====== GRADE TOO LOW TEST ======" << std::endl;
	{
		std::cout << std::endl;
		Bureaucrat b1("Jhon", 25);
		PresidentialPardonForm f1("Bob");
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << std::endl;
	}

	return 0;
}
