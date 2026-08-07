#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), brain(new Brain())
{
	std::cout << "\tDog Default Constuctor called\n";
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "\tDog Copy Constructor called\n";
	this->brain = new Brain(*other.brain);
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*brain = *rhs.brain;
	}
	return *this;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "\tDog Destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Bark\n";
}
