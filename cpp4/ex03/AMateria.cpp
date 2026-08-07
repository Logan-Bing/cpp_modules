#include "AMateria.hpp"
#include "Debug.hpp"

AMateria::AMateria(void)
{
	DEBUG_MSG("AMateria Default Constuctor called\n");
}

AMateria::AMateria(const std::string& type): type_(type)
{
	DEBUG_MSG("AMateria Type Constuctor called\n");
}

AMateria::AMateria(const AMateria& other): type_(other.type_)
{
	DEBUG_MSG("AMateria Copy Constructor called\n");
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

AMateria::~AMateria(void)
{
	DEBUG_MSG("\tAMateria Destructor called\n");
}

const std::string& AMateria::getType() const
{
	return type_;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
