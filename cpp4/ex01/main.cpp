#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
	std::cout << "42 TEST\n";
	std::cout << "\t"; const Animal* j = new Dog();
	std::cout << "\t"; const Animal* i = new Cat();

	delete j;
	delete i;
	std::cout << "--\n";

	std::cout << "DEEP COPY TEST\n";
	std::cout << "\t"; Cat cat1;
	std::cout << "\t"; Cat cat2;
	cat1[0] = "Alice";
	cat2[0] = "Jhon";
	std::cout << "\t"; std:: cout << "Before assignement cat1[0]: " << cat1[0] << std::endl;
	std::cout << "\t"; std:: cout << "Before assignement cat2[0]: " << cat2[0] << std::endl;
	cat1 = cat2;
	std::cout << "\t"; std:: cout << "After assignement cat1[0]: " << cat1[0] << std::endl;
	std::cout << "\t"; std:: cout << "After assignement cat2[0]: " << cat2[0] << std::endl;
	cat1[0] = "Alice";
	std::cout << "\t"; std:: cout << "After changement cat1[0]: " << cat1[0] << std::endl;
	std::cout << "\t"; std:: cout << "After changement cat2[0]: " << cat2[0] << std::endl;
	std::cout << "--\n";

	return 0;
}
