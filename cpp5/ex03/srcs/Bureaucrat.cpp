#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../utils/Debug.hpp"

#include <exception>
#include <iostream>

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& err): std::invalid_argument(err)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& err): std::invalid_argument(err)
{}

Bureaucrat::Bureaucrat(void): name_("default"), grade_(150)
{
	DEBUG_MSG("Bureaucrat Default Constuctor called\n");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade)
{
	gradeChecker_(grade_);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name_(other.name_), grade_(other.grade_)
{
	DEBUG_MSG("Bureaucrat Copy Constructor called\n");
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		grade_ = rhs.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	DEBUG_MSG("Bureaucrat Destructor called\n");
}

int	Bureaucrat::gradeChecker_(int grade)
{
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException(GRADE_RULES);
		return 0;
	}
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException(GRADE_RULES);
		return 0;
	}
	return 1;
}

const std::string& Bureaucrat::getName(void) const
{
	return name_;
}

int Bureaucrat::getGrade(void) const
{
	return grade_;
}

void	Bureaucrat::increment()
{
	int tmp_grade = grade_ - 1;
	if (!gradeChecker_(tmp_grade))
		return ;
	grade_ = tmp_grade;
}

void	Bureaucrat::decrement()
{
	int tmp_grade = grade_ + 1;
	if (!gradeChecker_(tmp_grade))
		return ;
	grade_ = tmp_grade;
}

void	Bureaucrat::signForm(AForm& f)
{
	try {
		f.beSigned(*this);
		std::cout << name_ << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << name_ + " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& f)
{
	try {
		f.execute(*this);
		std::cout << name_ << " executed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name_ + " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
