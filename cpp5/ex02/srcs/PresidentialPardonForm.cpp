#include "../includes/PresidentialPardonForm.hpp"
#include "../utils/Debug.hpp"
#include "../includes/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5),target_("")
{
	DEBUG_MSG("PresidentialPardonForm Default Constuctor called\n");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("PresidentialPardonForm", 25, 5), \
	target_(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other), \
	target_(other.target_)
{
	DEBUG_MSG("PresidentialPardonForm Copy Constructor called\n");
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target_ = rhs.target_;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	DEBUG_MSG("PresidentialPardonForm Destructor called\n");
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return target_;
}
