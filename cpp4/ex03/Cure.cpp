#include "Cure.hpp"
#include "Debug.hpp"
#include "AMateria.hpp"

Cure::Cure(void): AMateria("cure")
{
	DEBUG_MSG("Cure Default Constuctor called\n");
}

Cure::Cure(const Cure& other): AMateria(other)
{
	DEBUG_MSG("Cure Copy Constructor called\n");
}

Cure&	Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
	{
	
	}
	return *this;
}

Cure::~Cure(void)
{
	DEBUG_MSG("\tCure Destructor called\n");
}

AMateria* Cure::clone() const
{
	AMateria *res = new Cure();
	return res;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bold at " << target.getName() << " *" << std::endl;
}
