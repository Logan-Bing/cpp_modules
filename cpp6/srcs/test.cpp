// Tests unitaires des fonctions de detection (isChar, isInt, isFloat).
// Les helpers sont prives : on ouvre l'acces le temps de l'include.
#define private public
#include "../includes/ScalarConverter.hpp"
#undef private

#include <iostream>
#include <string>

static int g_total = 0;
static int g_failed = 0;

static void check(const char* fn, bool got, bool expected, const std::string& input)
{
	g_total++;
	if (got == expected)
		std::cout << "  \033[32mOK  \033[0m ";
	else
	{
		g_failed++;
		std::cout << "  \033[31mFAIL\033[0m ";
	}
	std::cout << fn << "([" << input << "]) = " << (got ? "true" : "false")
		<< "  attendu " << (expected ? "true" : "false") << std::endl;
}

static void testIsChar(void)
{
	std::cout << "\n=== isChar ===" << std::endl;
	// vrais
	check("isChar", ScalarConverter::isChar("'a'"), true, "'a'");
	check("isChar", ScalarConverter::isChar("'0'"), true, "'0'");
	check("isChar", ScalarConverter::isChar("' '"), true, "' '");
	check("isChar", ScalarConverter::isChar("'*'"), true, "'*'");
	check("isChar", ScalarConverter::isChar("'''"), true, "'''");
	// faux
	check("isChar", ScalarConverter::isChar(""), false, "");
	check("isChar", ScalarConverter::isChar("a"), false, "a");
	check("isChar", ScalarConverter::isChar("''"), false, "''");
	check("isChar", ScalarConverter::isChar("'ab'"), false, "'ab'");
	check("isChar", ScalarConverter::isChar("'a"), false, "'a");
	check("isChar", ScalarConverter::isChar("a'"), false, "a'");
	check("isChar", ScalarConverter::isChar("''a''"), false, "''a''");
	check("isChar", ScalarConverter::isChar("-42"), false, "-42");
	check("isChar", ScalarConverter::isChar("4.2"), false, "4.2");
	check("isChar", ScalarConverter::isChar("abc"), false, "abc");
	check("isChar", ScalarConverter::isChar("nan"), false, "nan");
}

static void testIsInt(void)
{
	std::cout << "\n=== isInt ===" << std::endl;
	// vrais
	check("isInt", ScalarConverter::isInt("0"), true, "0");
	check("isInt", ScalarConverter::isInt("42"), true, "42");
	check("isInt", ScalarConverter::isInt("-42"), true, "-42");
	check("isInt", ScalarConverter::isInt("+42"), true, "+42");
	check("isInt", ScalarConverter::isInt("2147483647"), true, "2147483647");
	check("isInt", ScalarConverter::isInt("-2147483648"), true, "-2147483648");
	// deborde a l'execution, mais la forme reste celle d'un int
	check("isInt", ScalarConverter::isInt("99999999999"), true, "99999999999");
	// faux : vide ou pas de chiffre
	check("isInt", ScalarConverter::isInt(""), false, "");
	check("isInt", ScalarConverter::isInt(" "), false, " ");
	check("isInt", ScalarConverter::isInt("-"), false, "-");
	check("isInt", ScalarConverter::isInt("+"), false, "+");
	check("isInt", ScalarConverter::isInt("abc"), false, "abc");
	// faux : caracteres en trop
	check("isInt", ScalarConverter::isInt("42abc"), false, "42abc");
	check("isInt", ScalarConverter::isInt("42 "), false, "42 ");
	check("isInt", ScalarConverter::isInt(" 42"), false, " 42");
	check("isInt", ScalarConverter::isInt("12-3"), false, "12-3");
	check("isInt", ScalarConverter::isInt("--42"), false, "--42");
	check("isInt", ScalarConverter::isInt("+-42"), false, "+-42");
	// faux : ce n'est pas un int
	check("isInt", ScalarConverter::isInt("4.2"), false, "4.2");
	check("isInt", ScalarConverter::isInt("4.2f"), false, "4.2f");
	check("isInt", ScalarConverter::isInt("42f"), false, "42f");
	check("isInt", ScalarConverter::isInt("0x2A"), false, "0x2A");
	check("isInt", ScalarConverter::isInt("1e10"), false, "1e10");
	check("isInt", ScalarConverter::isInt("42L"), false, "42L");
	check("isInt", ScalarConverter::isInt("'a'"), false, "'a'");
	check("isInt", ScalarConverter::isInt("nan"), false, "nan");
}

static void testIsFloat(void)
{
	std::cout << "\n=== isFloat ===" << std::endl;
	// vrais
	check("isFloat", ScalarConverter::isFloat("0.0f"), true, "0.0f");
	check("isFloat", ScalarConverter::isFloat("4.2f"), true, "4.2f");
	check("isFloat", ScalarConverter::isFloat("-4.2f"), true, "-4.2f");
	check("isFloat", ScalarConverter::isFloat("+4.2f"), true, "+4.2f");
	check("isFloat", ScalarConverter::isFloat("-0.0f"), true, "-0.0f");
	check("isFloat", ScalarConverter::isFloat("123.456f"), true, "123.456f");
	// faux : vide ou pas de chiffre
	check("isFloat", ScalarConverter::isFloat(""), false, "");
	check("isFloat", ScalarConverter::isFloat("f"), false, "f");
	check("isFloat", ScalarConverter::isFloat("."), false, ".");
	check("isFloat", ScalarConverter::isFloat("-"), false, "-");
	check("isFloat", ScalarConverter::isFloat(".f"), false, ".f");
	// faux : point manquant ou mal place
	check("isFloat", ScalarConverter::isFloat("42f"), false, "42f");
	check("isFloat", ScalarConverter::isFloat("42.f"), false, "42.f");
	check("isFloat", ScalarConverter::isFloat(".42f"), false, ".42f");
	check("isFloat", ScalarConverter::isFloat("1.2.3f"), false, "1.2.3f");
	check("isFloat", ScalarConverter::isFloat("4f.2"), false, "4f.2");
	// faux : suffixe incorrect
	check("isFloat", ScalarConverter::isFloat("4.2"), false, "4.2");
	check("isFloat", ScalarConverter::isFloat("4.2ff"), false, "4.2ff");
	check("isFloat", ScalarConverter::isFloat("4.2F"), false, "4.2F");
	check("isFloat", ScalarConverter::isFloat("4.2fx"), false, "4.2fx");
	// faux : autres types
	check("isFloat", ScalarConverter::isFloat("42"), false, "42");
	check("isFloat", ScalarConverter::isFloat("'a'"), false, "'a'");
	check("isFloat", ScalarConverter::isFloat("nanf"), false, "nanf");
	check("isFloat", ScalarConverter::isFloat("+inff"), false, "+inff");
}

int main(void)
{
	testIsChar();
	testIsInt();
	testIsFloat();

	std::cout << "\n---------------------------------" << std::endl;
	std::cout << g_total - g_failed << " / " << g_total << " tests passes";
	if (g_failed)
		std::cout << "  (\033[31m" << g_failed << " echecs\033[0m)";
	std::cout << std::endl;
	return (g_failed != 0);
}
