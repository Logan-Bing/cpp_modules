#include "Bureaucrat.hpp"
#include "Debug.hpp"

Bureaucrat::Bureaucrat(void)
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

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& err): std::invalid_argument(err)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& err): std::invalid_argument(err)
{}

int	Bureaucrat::gradeChecker_(int grade)
{
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooHighException("The value is too high");
		return 0;
	}
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooLowException("The value is too low");
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
