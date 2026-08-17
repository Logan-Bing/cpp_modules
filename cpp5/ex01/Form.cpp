#include "Form.hpp"
#include "Debug.hpp"

Form::GradeTooHighException::GradeTooHighException(const std::string& err): std::invalid_argument(err)
{}

Form::GradeTooLowException::GradeTooLowException(const std::string& err): std::invalid_argument(err)
{}

Form::Form(void): name_(""), gradeRequiredToSign_(0), gradeRequiredToExecute_(0), is_signed(false)
{
	DEBUG_MSG("Form Default Constuctor called\n");
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

const int Form::getGradeRequiredToSign() const
{
	return gradeRequiredToSign_;
}
 
const int Form::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute_;
}

const bool Form::getSignedStatus() const
{
	return is_signed;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() < gradeRequiredToSign_)
	{
		throw Form::GradeTooLowException(b.getName() + "couldn't sign form because his grade is too low");
		return ;
	}

	std::cout << b.getName() << "signed " << name_ << std::endl;
	is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	std::string status = !rhs.getSignedStatus() ? "No" : "Yes";

	os << "name: " << rhs.getName() << std::endl;
	os << "gradeRequiredToSign: " << rhs.getGradeRequiredToSign() << std::endl;
	os << "gradeRequiredToExecute: " << rhs.getName() << std::endl;
	os << "Signed: " << status << std::endl;

	return os;
}
