#include "../includes/ScalarConverter.hpp"
#include "../utils/Debug.hpp"
#include <cctype>
#include <cstddef>
#include <string>

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

// Pipeline
// - Reperer si c'est un pseudo litteraux
// - Trouver le type reel de l'input
// - Convertir le input en son type reel exemple: 1 -> int
// - Caster dans les autres types

bool	ScalarConverter::isValidChar(const std::string& ch)
{
	return !(ch == IMPOSSIBLE_TAG || ch == NON_DISPLAYABLE_TAG);
}

void	ScalarConverter::printChar(const std::string& ch)
{
	std::cout << "char: ";
	if (isValidChar(ch))
		std::cout << "'" << ch << "'" << std::endl;
	else
		std::cout << ch << std::endl;
}

bool ScalarConverter::isChar(const std::string& input)
{
	return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
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
	size_t i = 0;
	size_t start = 0;

	if (input[0] == '-' || input[0] == '+')
		i++;

	start = i;
	for (; i < input.length() && std::isdigit(input[i]); i++);

	if (start == i || input[i] != '.')
		return false;
	i++;

	start = i;
	for (; i < input.length() && std::isdigit(input[i]); i++);

	if (start == i || input[i] != 'f')
		return false;
	i++;

	return (i == input.length());
}

bool ScalarConverter::isDouble(const std::string& input)
{
	(void)input;
	// size_t i = 0;
	// if (input[0] == '-' || input[0] == '+')
	// 	i++;
	return true;
}

void	ScalarConverter::printAllTypes
(
	const std::string& ch,
	const std::string& i,
	const std::string& f,
	const std::string& d
)
{
	printChar(ch);
	std::cout << 
		"int: " << i << '\n' <<
		"float: " << f << '\n' <<
		"double: " << d << std::endl;
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
				"impossible",
				"impossible",
				pseudo_literals[i].float_repr,
				pseudo_literals[i].double_repr
			);
			return true;
		}
	}
	return false;
}


void	ScalarConverter::convert(const std::string &input)
{
	if (handlePseudoLitteral(input))
		return ;

	if (isChar(input))
		std::cout << "ok" << std::endl;
	if (isInt(input))
		std::cout << "isInt" << std::endl;
}
