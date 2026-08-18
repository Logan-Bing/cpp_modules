#include "../includes/header.hpp"
#include <iostream>

int main()
{
	try {
		Form f1("Foo", 0, 70); }
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f1("Foo", 200, 70); }
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f1("Foo", 70, 0); }
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f1("Foo", 70, 200); }
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat b1("Jhon", 100);
	Form f1("Foo", 50, 50);
	b1.signForm(f1);

	return 0;
}
