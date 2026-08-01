#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default Constuctor called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy Constructor called\n";
	*this = other;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < SIZE_IDEAS; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called\n";
}
