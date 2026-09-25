#include "../includes/ScalarConverter.hpp"
#include "../utils/Debug.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <string>

// inf n'est pas detectable via std::isinf en C++98 : on compare aux bornes.
static bool	isInfinite(double value)
{
	return (value > std::numeric_limits<double>::max()
		|| value < -std::numeric_limits<double>::max());
}

const ScalarConverter::LiteralMapping ScalarConverter::pseudo_literals[3] =
{
	{DOUBLE_NAN_REPR, FLOAT_NAN_REPR},
	{DOUBLE_INF_P_REPR, FLOAT_INF_P_REPR},
	{DOUBLE_INF_N_REPR, FLOAT_INF_N_REPR},
};

ScalarConverter::ScalarConverter(void)
{
	DEBUG_MSG("ScalarConverter Default Constuctor called\n");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	DEBUG_MSG("ScalarConverter Copy Constructor called\n");
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	if (this != &rhs)
	{
	
	}
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	DEBUG_MSG("ScalarConverter Destructor called\n");
}

bool ScalarConverter::handlePseudoLitteral(const std::string& input)
{
	for (int i = 0; i < 3; i++)
	{
		if 
		(
			input == pseudo_literals[i].double_repr ||
			input == pseudo_literals[i].float_repr
		)
		{
			printAllTypes
			(
				IMPOSSIBLE_TAG,
				IMPOSSIBLE_TAG,
				pseudo_literals[i].float_repr,
				pseudo_literals[i].double_repr
			);
			return true;
		}
	}
	return false;
}

void	ScalarConverter::printAllTypes
(
	const std::string& ch,
	const std::string& i,
	const std::string& f,
	const std::string& d
)
{
	std::cout <<
		"char: " << ch << '\n' <<
		"int: " << i << '\n' <<
		"float: " << f << '\n' <<
		"double: " << d << std::endl;
}

size_t	ScalarConverter::parseMantissa(const std::string& input)
{
	size_t i = 0;
	size_t start = 0;

	if (input[0] == '-' || input[0] == '+')
		i++;

	start = i;
	for (; i < input.length() && std::isdigit(input[i]); i++);

	if (start == i || input[i] != '.')
		return std::string::npos;
	i++;

	start = i;
	for (; i < input.length() && std::isdigit(input[i]); i++);

	if (start == i)
		return std::string::npos;

	return i;
}

bool ScalarConverter::isChar(const std::string& input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	// ./convert 'a' : le shell retire les quotes, on recoit "a" tout court.
	return (input.length() == 1 && !std::isdigit(input[0]));
}

bool ScalarConverter::isInt(const std::string& input)
{
	size_t i = 0;

	if (input[0] == '-' || input[0] == '+')
		i++;

	if (!std::isdigit(input[i]))
		return false;

	for (; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}

	return true;
}

bool ScalarConverter::isFloat(const std::string& input)
{
	size_t i = parseMantissa(input);
	return (i != std::string::npos && i + 1 == input.length() && input[i] == 'f');
}

bool ScalarConverter::isDouble(const std::string& input)
{
	size_t i = parseMantissa(input);
	return (i != std::string::npos && i == input.length());
}

void	ScalarConverter::printChar(double value)
{
	char ch = static_cast<char>(value);

	std::cout << "char: ";
	if (value < 0 || value > 127)
	{
		std::cout << IMPOSSIBLE_TAG << std::endl;
		return;
	}
	if (!std::isprint(ch))
	{
		std::cout << NON_DISPLAYABLE_TAG << std::endl;
		return;
	}
	else
	{
		std::cout << "'" << ch << "'" << std::endl;
		return;
	}
}

void	ScalarConverter::printInt(double value)
{
	std::cout << "int: ";
	if (value < INT_MIN || value > INT_MAX)
		std::cout << IMPOSSIBLE_TAG << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value)
{
	float			f = static_cast<float>(value);
	std::streamsize	prec = std::cout.precision();

	std::cout << "float: ";
	if (isInfinite(f))
	{
		std::cout << (f < 0 ? FLOAT_INF_N_REPR : FLOAT_INF_P_REPR) << std::endl;
		return;
	}
	if (f == std::floor(f) && std::fabs(f) < PRINT_FIXED_LIMIT)
		std::cout << std::fixed << std::setprecision(1) << f;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << f;
	std::cout << "f" << std::endl;
	// fixed/precision sont remanents sur le flux : printDouble en heriterait.
	std::cout.unsetf(std::ios::floatfield);
	std::cout.precision(prec);
}

void	ScalarConverter::printDouble(double value)
{
	std::streamsize	prec = std::cout.precision();

	std::cout << "double: ";
	if (isInfinite(value))
	{
		std::cout << (value < 0 ? DOUBLE_INF_N_REPR : DOUBLE_INF_P_REPR) << std::endl;
		return;
	}
	if (value == std::floor(value) && std::fabs(value) < PRINT_FIXED_LIMIT)
		std::cout << std::fixed << std::setprecision(1) << value;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << value;
	std::cout << std::endl;
	std::cout.unsetf(std::ios::floatfield);
	std::cout.precision(prec);
}


void	ScalarConverter::convert(const std::string &input)
{
	if (handlePseudoLitteral(input))
		return ;

	double value = 0.0;

	if (isChar(input))
	{
		value = static_cast<double>(input.length() == 1 ? input[0] : input[1]);
	}
	else if (isInt(input) || isFloat(input) || isDouble(input))
	{
		value = std::strtod(input.c_str(), NULL);
	}
	else
	{
		printAllTypes(IMPOSSIBLE_TAG, IMPOSSIBLE_TAG, IMPOSSIBLE_TAG, IMPOSSIBLE_TAG);
		return;
	}
	

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

