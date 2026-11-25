#include "../includes/Span.hpp"
#include "../utils/Debug.hpp"
#include <algorithm>
#include <limits>

Span::Span(void): elements_(0), size_(0)
{
	DEBUG_MSG("Span Default Constuctor called\n");
}

Span::Span(unsigned int N): size_(N)
{
	elements_.reserve(N);
}

Span::Span(const Span& other): size_(other.size_)
{
	DEBUG_MSG("Span Copy Constructor called\n");
	for (size_t i = 0; i < size_; i++)
		elements_[i] = other.elements_[i];
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		size_ = rhs.size_;
		elements_.clear();
		for (size_t i = 0; i < size_; i++)
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
	if (elements_.size() >= size_)
		throw std::out_of_range("ERROR: out of range");
	elements_.push_back(n);
}

void	Span::addNumbers(const ints_v::const_iterator& begin, const ints_v::const_iterator& end)
{
	for (ints_v::const_iterator it = begin; it != end; ++it)
	{
		elements_.push_back(*it);
	}
}

unsigned int Span::shortestSpan() const
{
	if (!elements_.size() || elements_.size() == 1)
		throw std::out_of_range("ERROR: not enough elements");

	unsigned int lowest_gap = std::numeric_limits<unsigned int>().max();

	ints_v copy(elements_);
	std::sort(copy.begin(), copy.end());

	ints_v::iterator last = --copy.end();

	for (ints_v::iterator it = copy.begin(); it != last; ++it)
	{
		ints_v::iterator next = it + 1;
		unsigned int gap = *next - *it;
		if (gap < lowest_gap)
			lowest_gap = gap;
	}
	return lowest_gap;
}

unsigned int Span::longestSpan() const
{
	if (!elements_.size() || elements_.size() == 1)
		throw std::out_of_range("ERROR: not enough elements");

	ints_v::const_iterator max = std::max_element(elements_.begin(), elements_.end());
	ints_v::const_iterator min = std::min_element(elements_.begin(), elements_.end());

	return static_cast<unsigned int>(*max) - static_cast<unsigned int>(*min);
}

void	Span::printElements() const
{
	std::cout << "[";
	for (ints_v::const_iterator it = elements_.begin(); it != elements_.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != elements_.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}
