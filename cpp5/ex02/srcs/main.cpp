#include "../includes/header.hpp"
#include <iostream>

int main()
{
	Bureaucrat b1("Jhon", 1);
	PresidentialPardonForm f1("Basic form");

	b1.signForm(f1);
	b1.executeForm(f1);
	return 0;
}
