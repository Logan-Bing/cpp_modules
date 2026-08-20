#include "../includes/ShrubberyCreationForm.hpp"
#include "../utils/Debug.hpp"
#include "../includes/AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137),target_("")
{
	DEBUG_MSG("ShrubberyCreationForm Default Constuctor called\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("ShrubberyCreationForm", 145, 137), \
	target_(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other), \
	target_(other.target_)
{
	DEBUG_MSG("ShrubberyCreationForm Copy Constructor called\n");
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target_ = rhs.target_;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	DEBUG_MSG("ShrubberyCreationForm Destructor called\n");
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream file;
	std::string file_name(target_ + "_shrubbery");

	file.open(file_name.c_str());

	if (!file.is_open())
	{
		std::cout << "Error: Can't open the file " << file_name << std::endl; 
		return;
	}

	file << "    *\n"
	        "   ***\n"
	        "  *****\n"
	        " *******\n"
	        "    |\n"
	        "    |\n";
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return target_;
}
