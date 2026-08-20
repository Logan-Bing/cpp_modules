#include "../includes/header.hpp"
#include "../utils/utils.hpp"
#include <ctime>

void	printValidTest(int grade, AForm& f, Bureaucrat& b)
{
		std::cout << f;
		std::cout << BG_YELLOW << BLACK << "Bureaucrat grade: " << grade << RESET << std::endl;
		std::cout << std::endl;

		b.signForm(f);
		b.executeForm(f);

		std::cout << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	std::cout << BG_GREEN << BLACK << "VALID TEST" << RESET << std::endl;
	{
		std::cout << std::endl;

		int grade1(5);
		PresidentialPardonForm f1("Bob");
		Bureaucrat b1("Jhon", grade1);
		printValidTest(grade1, f1, b1);

		int grade2(45);
		RobotomyRequestForm f2("Foo");
		Bureaucrat b2("Alice", grade2);
		printValidTest(grade2, f2, b2);

		int grade3(137);
		ShrubberyCreationForm f3("Boo");
		Bureaucrat b3("Toto", grade2);
		printValidTest(grade3, f3, b3);
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
