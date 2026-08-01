#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void*	get_vtable(void *obj)
{
	return *reinterpret_cast<void **>(obj);
}

int main()
{
	std::cout << "42 TEST\n";
	std::cout << "\t"; const Animal* meta = new Animal();
	std::cout << "\t"; const Animal* j = new Dog();
	std::cout << "\t"; const Animal* i = new Cat();
	std::cout << "\t"; std::cout << j->getType() << " " << std::endl;
	std::cout << "\t"; std::cout << i->getType() << " " << std::endl;
	std::cout << "\t"; i->makeSound(); //will output the cat sound!
	std::cout << "\t"; j->makeSound();
	std::cout << "\t"; meta->makeSound();
	delete i; delete j;
	std::cout << "--\n";

	std::cout << "VPTR / VTABLE\n";
	std::cout << "\t"; Cat cat1;
	std::cout << "\t"; Cat cat2;
	std::cout << "\t"; std::cout <<  "Vtable address of cat1: " << get_vtable(&cat1) << std::endl;
	std::cout << "\t"; std::cout <<  "Vtable address of cat2: " << get_vtable(&cat2) << std::endl;
	std::cout << "--\n";

	std::cout << "WRONG ANIMAL TEST\n";
	std::cout << "\t"; const WrongAnimal* c = new WrongCat();
	std::cout << "\t"; c->makeSound();
	std::cout << "--\n";
	return 0;
}
