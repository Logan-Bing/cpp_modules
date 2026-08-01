#include "Cat.hpp"

Cat::Cat(void): Animal(), type_("Cat")
{
	this->type_ = "Cat";
	std::cout << "\tCat Default Constuctor called\n";
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "\tCat Copy Constructor called\n";
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "\tCat Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Miaow\n";
}
