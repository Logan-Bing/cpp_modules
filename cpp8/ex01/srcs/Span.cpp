#include "../includes/Span.hpp"
#include "../utils/Debug.hpp"
#include "../includes/iter.hpp"

#include <algorithm>

Span::Span(void): elements_(0), max_size_(0)
{
	DEBUG_MSG("Span Default Constuctor called\n");
}

Span::Span(unsigned int N): max_size_(N)
{
	elements_.reserve(N);
}

Span::Span(const Span& other): max_size_(other.max_size_)
{
	DEBUG_MSG("Span Copy Constructor called\n");
	for (size_t i = 0; i < max_size_; i++)
		elements_[i] = other.elements_[i];
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		max_size_ = rhs.max_size_;
		elements_.clear();
		for (size_t i = 0; i < max_size_; i++)
			elements_[i] = rhs.elements_[i];
	}
	return *this;
}

Span::~Span(void)
{
	elements_.clear();
}

void	Span::addNumber(int n)
{
	if (elements_.size() >= max_size_)
		throw std::out_of_range("out of range");
	elements_.push_back(n);
}

void	Span::addNumbers(ints_v::const_iterator begin, ints_v::const_iterator last)
{
	for (ints_v::const_iterator it = begin; begin != last; ++it)
	{
		elements_.push_back(*it);
	}
}

unsigned int Span::shortestSpan() const
{
	if (!elements_.size() || elements_.size() == 1)
		throw std::out_of_range("not enough elements");
	return 0;
}

unsigned int Span::longestSpan() const
{
	if (!elements_.size() || elements_.size() == 1)
		throw std::out_of_range("not enough elements");

	ints_v::const_iterator max = std::max_element(elements_.begin(), elements_.end());
	ints_v::const_iterator min = std::min_element(elements_.begin(), elements_.end());

	return static_cast<unsigned int>(*max) - static_cast<unsigned int>(*min);
}

void	Span::printElements() const
{
	for (ints_v::const_iterator it = elements_.begin(); it != elements_.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}
