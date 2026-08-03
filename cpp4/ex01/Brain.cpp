#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "\tBrain Default Constuctor called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "\tBrain Copy Constructor called\n";
	*this = other;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < SIZE_IDEAS; i++)
			this->ideas_[i] = rhs.ideas_[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "\tBrain Destructor called\n";
}

std::string& Brain::operator[](std::size_t idx)
{
	return ideas_[idx];
}

const std::string& Brain::operator[](std::size_t idx) const
{
	return ideas_[idx];
}

