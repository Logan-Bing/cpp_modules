#include "../includes/ScalarConverter.hpp"
#include <ios>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <vector>
#define NB_TEST 5

int main()
{
	std::streambuf* origin = std::cout.rdbuf();
	std::stringstream outputStream[NB_TEST];

	std::string args[NB_TEST] =
	{
		"a",         // 1. Caractère standard
		"42",        // 2. Entier (ASCII 42 = '*')
		"42.42f",    // 3. Float avec décimales
		"nan",       // 4. Valeur spéciale NaN (Not a Number)
		"inff"       // 5. Valeur spéciale Infini positif
	};

	std::string expects[NB_TEST] =
	{
		"char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n",
		"char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n",
		"char: '*'\nint: 42\nfloat: 42.42f\ndouble: 42.42\n",
		"char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n",
		"char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n"
	};


	for (size_t i = 0; i < NB_TEST; i++)
	{
		std::cout.rdbuf(outputStream[i].rdbuf());
		ScalarConverter::convert(args[i]);
		std::cout.rdbuf(origin);

		std::string output = outputStream[i].str();

		if (output == expects[i])
		{
			std::cout << "[SUCCESS]" << std::endl;
		}
		else
		{
			std::cout << "[ECHEC]" << std::endl;
			std::cout << "expected:\n" << expects[i];
			std::cout << "output:\n" << output;
		}
	}
}
