#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../utils/Debug.hpp"

#include <iostream>

Form::GradeTooHighException::GradeTooHighException(const std::string& err): std::invalid_argument(err)
{}

Form::GradeTooLowException::GradeTooLowException(const std::string& err): std::invalid_argument(err)
{}

Form::Form(void): name_(""), gradeRequiredToSign_(150), gradeRequiredToExecute_(150), is_signed(false)
{
	DEBUG_MSG("Form Default Constuctor called\n");
}

Form::Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute):
	name_(name), \
	gradeRequiredToSign_(gradeRequiredToSign), \
	gradeRequiredToExecute_(gradeRequiredToExecute), \
	is_signed(false)
{
	gradeChecker_(gradeRequiredToSign_);
	gradeChecker_(gradeRequiredToExecute_);
}

Form::Form(const Form& other):
	name_(other.name_), \
	gradeRequiredToSign_(other.gradeRequiredToSign_), \
	gradeRequiredToExecute_(other.gradeRequiredToExecute_), \
	is_signed(other.is_signed)
{
	DEBUG_MSG("Form Copy Constructor called\n");
}

Form&	Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		is_signed = rhs.is_signed;
	return *this;
}

Form::~Form(void)
{
	DEBUG_MSG("Form Destructor called\n");
}

const std::string& Form::getName() const
{
	return name_;
}

int Form::getGradeRequiredToSign() const
{
	return gradeRequiredToSign_;
}
 
int Form::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute_;
}

bool Form::getSignedStatus() const
{
	return is_signed;
}

void	Form::gradeChecker_(int grade)
{
	if (grade > 150) throw Form::GradeTooLowException(GRADE_RULES);
	if (grade < 1) throw Form::GradeTooHighException(GRADE_RULES);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeRequiredToSign_)
		throw Form::GradeTooLowException("grade too low");

	is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	std::string status = !rhs.getSignedStatus() ? "No" : "Yes";

	os << "name: " << rhs.getName() << std::endl;
	os << "gradeRequiredToSign: " << rhs.getGradeRequiredToSign() << std::endl;
	os << "gradeRequiredToExecute: " << rhs.getGradeRequiredToExecute() << std::endl;
	os << "Signed: " << status;
	return os;
}
