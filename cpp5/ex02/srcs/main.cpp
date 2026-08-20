#include "../includes/header.hpp"
#include "../utils/utils.hpp"
#include <iomanip>
#include <iostream>

int main()
{
	std::cout << BG_GREEN << BLACK << "VALID TEST" << RESET << std::endl;
	{
		int grade = 5;
		PresidentialPardonForm f1("Bob");
		Bureaucrat b1("Jhon", grade);

		std::cout << std::endl;
		std::cout << f1;
		std::cout << std::endl;


		b1.signForm(f1);

		PresidentialPardonForm f2("Alice");
		f2 = f1;

		b1.executeForm(f2);

		std::cout << std::endl;
	}
	// std::cout << BG_GREEN << BLACK << "NOT SIGNED TEST" << RESET << std::endl;
	// {
	// 	std::cout << std::endl;
	// 	Bureaucrat b1("Jhon", 1);
	// 	PresidentialPardonForm f1("Bob");
	// 	b1.executeForm(f1);
	// 	std::cout << std::endl;
	// }
	// std::cout << BG_GREEN << BLACK << "GRADE TOO LOW TEST" << RESET << std::endl;
	// {
	// 	std::cout << std::endl;
	// 	Bureaucrat b1("Jhon", 25);
	// 	PresidentialPardonForm f1("Bob");
	// 	b1.signForm(f1);
	// 	b1.executeForm(f1);
	// 	std::cout << std::endl;
	// }
	// std::cout << BG_GREEN << BLACK << "VIRTUAL TEST" << RESET << std::endl;
	// {
	// 	AForm *f1 = new PresidentialPardonForm("Bob");
	// 	Bureaucrat b1("Jhon", 1);
	// 	b1.signForm(*f1);
	// 	b1.executeForm(*f1);
	// 	delete f1;
	// }

	return 0;
}
