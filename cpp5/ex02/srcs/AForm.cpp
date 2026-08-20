#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../utils/Debug.hpp"
#include "../utils/utils.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

// Largeurs du bloc affiche par operator<<
#define LABEL_W 25
#define ROW_W   50

AForm::FormNotSignedException::FormNotSignedException(const std::string& err): std::invalid_argument(err)
{}

AForm::GradeTooHighException::GradeTooHighException(const std::string& err): std::invalid_argument(err)
{}

AForm::GradeTooLowException::GradeTooLowException(const std::string& err): std::invalid_argument(err)
{}

AForm::AForm(void): name_(""), gradeRequiredToSign_(150), gradeRequiredToExecute_(150), is_signed(false)
{
	DEBUG_MSG("AForm Default Constuctor called\n");
}

AForm::AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute):
	name_(name), \
	gradeRequiredToSign_(gradeRequiredToSign), \
	gradeRequiredToExecute_(gradeRequiredToExecute), \
	is_signed(false)
{
	gradeChecker_(gradeRequiredToSign_);
	gradeChecker_(gradeRequiredToExecute_);
}

AForm::AForm(const AForm& other):
	name_(other.name_), \
	gradeRequiredToSign_(other.gradeRequiredToSign_), \
	gradeRequiredToExecute_(other.gradeRequiredToExecute_), \
	is_signed(other.is_signed)
{
	DEBUG_MSG("AForm Copy Constructor called\n");
}

AForm&	AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		is_signed = rhs.is_signed;
	return *this;
}

AForm::~AForm(void)
{
	DEBUG_MSG("AForm Destructor called\n");
}

const std::string& AForm::getName() const
{
	return name_;
}

int AForm::getGradeRequiredToSign() const
{
	return gradeRequiredToSign_;
}
 
int AForm::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute_;
}

bool AForm::getSignedStatus() const
{
	return is_signed;
}

void	AForm::gradeChecker_(int grade)
{
	if (grade > 150) throw AForm::GradeTooLowException(GRADE_RULES);
	if (grade < 1) throw AForm::GradeTooHighException(GRADE_RULES);
}

void	AForm::formChecker_(const Bureaucrat& b) const
{
	if (b.getGrade() > gradeRequiredToExecute_)
		throw AForm::GradeTooLowException(b.getName() + " grade too low");
	if (!is_signed)
		throw AForm::FormNotSignedException(name_ + " is not signed");
}

void	AForm::execute(const Bureaucrat& executor) const
{
	formChecker_(executor);
	executeAction();
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeRequiredToSign_)
		throw AForm::GradeTooLowException("grade too low");

	is_signed = true;
}

static void	printTitle(std::ostream& os, const std::string& title)
{
	os << BG_WHITE << BOLD_BLACK
	   << std::left << std::setw(ROW_W) << title
	   << RESET << '\n';
}

static void	printRow(std::ostream& os, const std::string& label, const std::string& value)
{
	std::ostringstream	line;

	line << std::left << std::setw(LABEL_W) << label << value;
	os << BG_WHITE << BLACK
	   << std::left << std::setw(ROW_W) << line.str()
	   << RESET << '\n';
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	std::ostringstream	sign, exec;

	sign << rhs.getGradeRequiredToSign();
	exec << rhs.getGradeRequiredToExecute();
	printTitle(os, rhs.getName());
	printRow(os, "Target:", rhs.getTarget());
	printRow(os, "GradeRequiredToSign:", sign.str());
	printRow(os, "GradeRequiredToExecute:", exec.str());
	printRow(os, "Signed:", rhs.getSignedStatus() ? "Yes" : "No");
	return os;
}
