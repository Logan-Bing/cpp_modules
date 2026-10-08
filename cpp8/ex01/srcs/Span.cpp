#include "../includes/Span.hpp"
#include "../utils/Debug.hpp"

Span::Span(void)
{
	DEBUG_MSG("Span Default Constuctor called\n");
}

Span::Span(const Span& other)
{
	DEBUG_MSG("Span Copy Constructor called\n");
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
	
	}
	return *this;
}

Span::~Span(void)
{
	DEBUG_MSG("Span Destructor called\n");
}
