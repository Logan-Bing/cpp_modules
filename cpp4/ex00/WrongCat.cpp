#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->type_ = "WrongCat";
	std::cout << "\tWrongCat Default Constuctor called\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "\tWrongCat Copy Constructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "\tWrongCat Destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaow\n";
}
