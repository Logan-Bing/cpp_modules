#include "Animal.hpp"

Animal::Animal(void): type_("")
{
	std::cout << "Animal Default Constuctor called\n";
}

Animal::Animal(const std::string& type): type_(type)
{
	std::cout << "Animal Type Constuctor called\n";
}

Animal::Animal(const Animal& other): type_(other.type_)
{
	std::cout << "Animal Copy Constructor called\n";
}

Animal&	Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
	{
		this->type_ = rhs.type_;
	}
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "\tAnimal Destructor called\n";
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound\n";
}

const std::string&	Animal::getType(void) const
{
	return this->type_;
}
