#include "../includes/Intern.hpp"
#include "../utils/Debug.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <algorithm>
#include <cctype>

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

int	charToLower(int ch)
{
	return std::tolower(ch);
}

std::string strToLower(const std::string& s)
{
	std::string res;
	res.resize(s.length());
	std::transform(s.begin(), s.end(), res.begin(), charToLower);

	return res;
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	std::string form_lower(strToLower(form));

	for (int i = 0; i < NB_OF_FORM; i++)
	{
		if (form_lower == forms[i].name)
			return forms[i].constructor(target);
	}

	return NULL;
}
