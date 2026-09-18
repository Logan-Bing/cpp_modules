#include "../includes/ScalarConverter.hpp"
#include "../utils/Debug.hpp"

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

bool	ScalarConverter::handleChar(const std::string& input)
{
}

void	ScalarConverter::convert(const std::string &input)
{
	if (handlePseudoLitteral(input))
		return ;
}
