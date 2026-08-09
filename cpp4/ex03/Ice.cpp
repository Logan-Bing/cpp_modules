#include "Ice.hpp"
#include "Debug.hpp"
#include "AMateria.hpp"

Ice::Ice(void): AMateria("cure")
{
	DEBUG_MSG("Ice Default Constuctor called\n");
}

Ice::Ice(const Ice& other): AMateria(other)
{
	DEBUG_MSG("Ice Copy Constructor called\n");
}

Ice&	Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
	{
	
	}
	return *this;
}

Ice::~Ice(void)
{
	DEBUG_MSG("\tIce Destructor called\n");
}

AMateria* Ice::clone() const
{
	AMateria *res = new Ice();
	return res;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bold at " << target.getName() << " *" << std::endl;
}
