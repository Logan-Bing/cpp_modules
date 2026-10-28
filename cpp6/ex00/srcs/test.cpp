#include "../includes/ScalarConverter.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <streambuf>
#include <sstream>
#include <string>
#define NB_TEST 80

namespace
{
	const char* const RESET = "\033[0m";
	const char* const BOLD = "\033[1m";
	const char* const DIM = "\033[2m";
	const char* const GREEN = "\033[32m";
	const char* const RED = "\033[31m";
	const char* const CYAN = "\033[36m";

	std::string formatArgument(const std::string& arg)
	{
		std::string escaped;
		for (std::string::size_type i = 0; i < arg.size(); ++i)
		{
			switch (arg[i])
			{
				case '\\': escaped += "\\\\"; break;
				case '"': escaped += "\\\""; break;
				case '\n': escaped += "\\n"; break;
				case '\r': escaped += "\\r"; break;
				case '\t': escaped += "\\t"; break;
				default: escaped += arg[i]; break;
			}
		}

		std::ostringstream label;
		if (escaped.size() > 54)
			label << '"' << escaped.substr(0, 32) << "..."
				<< escaped.substr(escaped.size() - 12) << '"'
				<< " (" << arg.size() << " caracteres)";
		else
			label << '"' << escaped << '"';
		return label.str();
	}

	void printComparison(const std::string& expected, const std::string& output)
	{
		std::istringstream expectedLines(expected);
		std::istringstream outputLines(output);
		std::ios::fmtflags flags = std::cout.flags();

		std::cout << DIM << "    " << std::left << std::setw(36)
			<< "ATTENDU" << " | OBTENU" << RESET << '\n';
		while (true)
		{
			std::string expectedLine;
			std::string outputLine;
			bool hasExpected = !!std::getline(expectedLines, expectedLine);
			bool hasOutput = !!std::getline(outputLines, outputLine);
			if (!hasExpected && !hasOutput)
				break;
			bool same = hasExpected && hasOutput && expectedLine == outputLine;
			if (!hasExpected)
				expectedLine = "<ligne absente>";
			if (!hasOutput)
				outputLine = "<ligne absente>";

			std::cout << "    " << (same ? DIM : GREEN)
				<< std::setw(36) << expectedLine << RESET
				<< DIM << " | " << RESET << (same ? DIM : RED)
				<< outputLine << RESET << '\n';
		}
		std::cout.flags(flags);
		std::cout << '\n';
	}
}

int main()
{
	std::streambuf* origin = std::cout.rdbuf();
	std::stringstream outputStream[NB_TEST];

	std::string args[NB_TEST] =
	{
		// Caracteres
		"a", // 1. caractere simple
		"Z", // 2. majuscule
		"*", // 3. ponctuation
		" ", // 4. espace
		"'0'", // 5. chiffre entre apostrophes
		"'a'", // 6. lettre entre apostrophes
		"+", // 7. signe seul : caractere
		"-", // 8. signe seul : caractere

		// Entiers
		"0", // 9. 0
		"1", // 10. 1
		"-1", // 11. -1
		"31", // 12. 31
		"32", // 13. 32
		"42", // 14. 42
		"65", // 15. 65
		"126", // 16. 126
		"127", // 17. 127
		"128", // 18. 128
		"-42", // 19. -42
		"+42", // 20. +42
		"16777216", // 21. 16777216
		"16777217", // 22. 16777217
		"2147483647", // 23. 2147483647
		"-2147483648", // 24. -2147483648

		// Doubles
		"0.0", // 25. 0.0
		"-0.0", // 26. -0.0
		"42.0", // 27. 42.0
		"-4.25", // 28. -4.25
		"65.5", // 29. 65.5
		"0.1", // 30. 0.1
		"42.42", // 31. 42.42
		"42.9999999", // 32. 42.9999999
		"16777217.0", // 33. 16777217.0
		"2147483648.0", // 34. 2147483648.0
		"-2147483649.0", // 35. -2147483649.0
		"0.000001", // 36. 0.000001
		"0.00000001", // 37. 0.00000001

		// Floats : partir de la valeur float avant les autres conversions
		"0.0f", // 38. 0.0f
		"-0.0f", // 39. -0.0f
		"42.0f", // 40. 42.0f
		"-4.25f", // 41. -4.25f
		"65.5f", // 42. 65.5f
		"0.1f", // 43. 0.1f
		"42.42f", // 44. 42.42f
		"4.2f", // 45. 4.2f
		"-4.2f", // 46. -4.2f
		"42.9999999f", // 47. 42.9999999f
		"16777217.0f", // 48. 16777217.0f
		"2147483647.0f", // 49. 2147483647.0f

		// Limites et depassements
		"340282346638528859811704183484516925440.0f", // 50. +float::max()
		"-340282346638528859811704183484516925440.0f", // 51. -float::max()
		"1000000000000000000000000000000000000000.0", // 52. double valide, trop grand pour float
		"-1000000000000000000000000000000000000000.0", // 53. double valide, trop negatif pour float
		"1000000000000000000000000000000000000000.0f", // 54. depassement du type source float
		"-1000000000000000000000000000000000000000.0f", // 55. depassement negatif du type source float
		"1" + std::string(309, '0') + ".0", // 56. 10 puissance 309 en notation decimale
		"-1" + std::string(309, '0') + ".0", // 57. -10 puissance 309 en notation decimale

		// Pseudo-litteraux
		"nan", // 58. nan
		"nanf", // 59. nanf
		"+inf", // 60. +inf
		"-inf", // 61. -inf
		"+inff", // 62. +inff
		"-inff", // 63. -inff

		// Entrees invalides
		"", // 64. chaine vide
		"abc", // 65. "abc"
		"'ab'", // 66. "'ab'"
		"42abc", // 67. "42abc"
		"42ff", // 68. "42ff"
		"4.2ff", // 69. "4.2ff"
		"4.2.1", // 70. "4.2.1"
		"++42", // 71. "++42"
		"--42", // 72. "--42"
		"+-42", // 73. "+-42"
		"42 42", // 74. "42 42"
		" 42", // 75. " 42"
		"42 ", // 76. "42 "
		"42f", // 77. "42f"
		"1,5", // 78. "1,5"
		"nanfoo", // 79. "nanfoo"
		"--4.2f" // 80. "--4.2f"
	};

	std::string expects[NB_TEST] =
	{
		// Caracteres
		"char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n", // 1
		"char: 'Z'\nint: 90\nfloat: 90.0f\ndouble: 90.0\n", // 2
		"char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n", // 3
		"char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0\n", // 4
		"char: '0'\nint: 48\nfloat: 48.0f\ndouble: 48.0\n", // 5
		"char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n", // 6
		"char: '+'\nint: 43\nfloat: 43.0f\ndouble: 43.0\n", // 7
		"char: '-'\nint: 45\nfloat: 45.0f\ndouble: 45.0\n", // 8

		// Entiers
		"char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n", // 9
		"char: Non displayable\nint: 1\nfloat: 1.0f\ndouble: 1.0\n", // 10
		"char: impossible\nint: -1\nfloat: -1.0f\ndouble: -1.0\n", // 11
		"char: Non displayable\nint: 31\nfloat: 31.0f\ndouble: 31.0\n", // 12
		"char: ' '\nint: 32\nfloat: 32.0f\ndouble: 32.0\n", // 13
		"char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n", // 14
		"char: 'A'\nint: 65\nfloat: 65.0f\ndouble: 65.0\n", // 15
		"char: '~'\nint: 126\nfloat: 126.0f\ndouble: 126.0\n", // 16
		"char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0\n", // 17
		"char: impossible\nint: 128\nfloat: 128.0f\ndouble: 128.0\n", // 18
		"char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n", // 19
		"char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n", // 20
		"char: impossible\nint: 16777216\nfloat: 16777216.0f\ndouble: 16777216.0\n", // 21
		"char: impossible\nint: 16777217\nfloat: 16777216.0f\ndouble: 16777217.0\n", // 22
		"char: impossible\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0\n", // 23
		"char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0\n", // 24

		// Doubles
		"char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n", // 25
		"char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n", // 26
		"char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n", // 27
		"char: impossible\nint: -4\nfloat: -4.25f\ndouble: -4.25\n", // 28
		"char: 'A'\nint: 65\nfloat: 65.5f\ndouble: 65.5\n", // 29
		"char: Non displayable\nint: 0\nfloat: 0.1f\ndouble: 0.1\n", // 30
		"char: '*'\nint: 42\nfloat: 42.42f\ndouble: 42.42\n", // 31
		"char: '*'\nint: 42\nfloat: 43.0f\ndouble: 42.9999999\n", // 32
		"char: impossible\nint: 16777217\nfloat: 16777216.0f\ndouble: 16777217.0\n", // 33
		"char: impossible\nint: impossible\nfloat: 2147483648.0f\ndouble: 2147483648.0\n", // 34
		"char: impossible\nint: impossible\nfloat: -2147483648.0f\ndouble: -2147483649.0\n", // 35
		"char: Non displayable\nint: 0\nfloat: 1e-06f\ndouble: 1e-06\n", // 36
		"char: Non displayable\nint: 0\nfloat: 1e-08f\ndouble: 1e-08\n", // 37

		// Floats : partir de la valeur float avant les autres conversions
		"char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n", // 38
		"char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n", // 39
		"char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n", // 40
		"char: impossible\nint: -4\nfloat: -4.25f\ndouble: -4.25\n", // 41
		"char: 'A'\nint: 65\nfloat: 65.5f\ndouble: 65.5\n", // 42
		"char: Non displayable\nint: 0\nfloat: 0.1f\ndouble: 0.100000001490116\n", // 43
		"char: '*'\nint: 42\nfloat: 42.42f\ndouble: 42.4199981689453\n", // 44
		"char: Non displayable\nint: 4\nfloat: 4.2f\ndouble: 4.19999980926514\n", // 45
		"char: impossible\nint: -4\nfloat: -4.2f\ndouble: -4.19999980926514\n", // 46
		"char: '+'\nint: 43\nfloat: 43.0f\ndouble: 43.0\n", // 47
		"char: impossible\nint: 16777216\nfloat: 16777216.0f\ndouble: 16777216.0\n", // 48
		"char: impossible\nint: impossible\nfloat: 2147483648.0f\ndouble: 2147483648.0\n", // 49

		// Limites et depassements
		"char: impossible\nint: impossible\nfloat: 3.40282e+38f\ndouble: 3.40282346638529e+38\n", // 50
		"char: impossible\nint: impossible\nfloat: -3.40282e+38f\ndouble: -3.40282346638529e+38\n", // 51
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: 1e+39\n", // 52
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: -1e+39\n", // 53
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 54
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 55
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 56
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 57

		// Pseudo-litteraux
		"char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n", // 58
		"char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n", // 59
		"char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n", // 60
		"char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n", // 61
		"char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n", // 62
		"char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n", // 63

		// Entrees invalides
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 64
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 65
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 66
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 67
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 68
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 69
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 70
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 71
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 72
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 73
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 74
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 75
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 76
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 77
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 78
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n", // 79
		"char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n" // 80
	};


	size_t passed = 0;
	std::cout << '\n' << BOLD << CYAN << "ScalarConverter - " << NB_TEST
		<< " tests" << RESET << '\n'
		<< DIM << std::string(78, '=') << RESET << "\n\n";

	for (size_t i = 0; i < NB_TEST; i++)
	{
		std::cout.rdbuf(outputStream[i].rdbuf());
		ScalarConverter::convert(args[i]);
		std::cout.rdbuf(origin);

		std::string output = outputStream[i].str();
		bool success = output == expects[i];

		std::cout << DIM << '[' << std::setw(2) << i + 1 << '/' << NB_TEST
			<< "] " << RESET << (success ? GREEN : RED) << BOLD
			<< (success ? "[OK]    " : "[ECHEC] ") << RESET
			<< formatArgument(args[i]) << '\n';

		if (success)
			++passed;
		else
			printComparison(expects[i], output);
	}

	std::cout << '\n' << DIM << std::string(78, '=') << RESET << '\n'
		<< BOLD << "BILAN  " << RESET << GREEN << passed << '/' << NB_TEST
		<< " reussis" << RESET << "  |  "
		<< (passed == NB_TEST ? GREEN : RED) << NB_TEST - passed
		<< " echec(s)" << RESET << "\n\n";
}
