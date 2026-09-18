#include "../includes/ScalarConverter.hpp"
#include "../utils/Debug.hpp"

ScalarConverter::ScalarConverter(void)
{
	DEBUG_MSG("ScalarConverter Default Constuctor called\n");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	DEBUG_MSG("ScalarConverter Copy Constructor called\n");
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (this != &rhs)
	{
	
	}
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	DEBUG_MSG("ScalarConverter Destructor called\n");
}

void	ScalarConverter::convert(const std::string &input)
{

}
