#include "../includes/Serializer.hpp"
#include "../utils/Debug.hpp"
#include <cstdint>

Serializer::Serializer(void)
{
	DEBUG_MSG("Serializer Default Constuctor called\n");
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	DEBUG_MSG("Serializer Copy Constructor called\n");
}

Serializer&	Serializer::operator=(const Serializer& rhs)
{
	if (this != &rhs)
	{
	
	}
	return *this;
}

Serializer::~Serializer(void)
{
	DEBUG_MSG("Serializer Destructor called\n");
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
