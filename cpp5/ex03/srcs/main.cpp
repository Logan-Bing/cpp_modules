#include "../includes/header.hpp"
#include "../utils/utils.hpp"

int main()
{
	AForm* shrubbery;
	AForm* presidential;
	AForm* robotomy;
	Intern intern;

	shrubbery = intern.makeForm("ShrubberyCreation", "bob");
	robotomy = intern.makeForm(ROBOTOMY_TAG, "bob");
	presidential = intern.makeForm(PRESIDENTIAL_TAG, "bob");

	if (shrubbery)
		std::cout << *shrubbery;
	else
		std::cout << "NULL" << std::endl;
	std::cout << *robotomy;
	std::cout << *presidential;

	delete shrubbery;
	delete robotomy;
	delete presidential;

	return 0;
}
