#include "../includes/Intern.hpp"
#include "../utils/Debug.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

const Intern::Form Intern::forms[NB_OF_FORM] = {
	{ SHRUBBERY_TAG,  &ShrubberyCreationForm::create },
	{ ROBOTOMY_TAG,    &RobotomyRequestForm::create },
	{ PRESIDENTIAL_TAG, &PresidentialPardonForm::create }
};

Intern::Intern(void)
{
	DEBUG_MSG("Intern Default Constuctor called\n");
}

Intern::Intern(const Intern& other)
{
	(void)other;
	DEBUG_MSG("Intern Copy Constructor called\n");
}

Intern&	Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern(void)
{
	DEBUG_MSG("Intern Destructor called\n");
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	for (int i = 0; i < NB_OF_FORM; i++)
	{
		if (form == forms[i].name)
		{
			std::cout << "Intern creates " << form<< std::endl;
			return forms[i].constructor(target);
		}
	}

	std::cout << "Error: No form named " << form << std::endl;
	return NULL;
}
