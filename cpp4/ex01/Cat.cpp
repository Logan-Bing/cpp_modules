#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), brain(new Brain())
{
	std::cout << "\tCat Default Constuctor called\n";
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "\tCat Copy Constructor called\n";
	this->brain = new Brain(*other.brain);
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*this->brain = *rhs.brain;
	}
	return *this;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "\tCat Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Miaow\n";
}

std::string& Cat::operator[](std::size_t idx)
{
	return (*brain)[idx];
}

const std::string& Cat::operator[](std::size_t idx) const
{
	return (*brain)[idx];
}

