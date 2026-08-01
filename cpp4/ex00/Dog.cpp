#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	this->type_ = "Dog";
	std::cout << "\tDog Default Constuctor called\n";
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "\tDog Copy Constructor called\n";
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "\tDog Destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Bark\n";
}
