#include "../includes/PresidentialPardonForm.hpp"
#include "../utils/Debug.hpp"
#include "../includes/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm()
{
	DEBUG_MSG("PresidentialPardonForm Default Constuctor called\n");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name): AForm(name, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
	DEBUG_MSG("PresidentialPardonForm Copy Constructor called\n");
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	DEBUG_MSG("PresidentialPardonForm Destructor called\n");
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	formChecker_(executor);
}
