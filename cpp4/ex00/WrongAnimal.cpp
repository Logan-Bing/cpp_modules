#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type_("")
{
	std::cout << "WrongAnimal Default Constuctor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy Constructor called\n";
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
	{
		this->type_ = rhs.type_;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound\n";
}

const std::string&	WrongAnimal::getType(void) const
{
	return this->type_;
}
