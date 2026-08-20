#include "../includes/RobotomyRequestForm.hpp"
#include "../utils/Debug.hpp"
#include "../includes/AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45),target_("")
{
	DEBUG_MSG("RobotomyRequestForm Default Constuctor called\n");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", 72, 45), \
	target_(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other), \
	target_(other.target_)
{
	DEBUG_MSG("RobotomyRequestForm Copy Constructor called\n");
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target_ = rhs.target_;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	DEBUG_MSG("RobotomyRequestForm Destructor called\n");
}

void	RobotomyRequestForm::executeAction() const
{
	bool tf = rand() % 2 != 0;

	if (tf)
		std::cout << target_ + " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return target_;
}
