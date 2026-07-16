#include "Fixed.hpp"

Fixed::Fixed(void): value_(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int v): value_(v << FRACTIONAL_BITS)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float v)
{
	this->value_ = static_cast<int>(roundf(v *(1 << FRACTIONAL_BITS)));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other): value_(other.value_)
{
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::toInt(void) const
{
	return this->value_ >> FRACTIONAL_BITS;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->value_) / (1 << FRACTIONAL_BITS);
}

int	Fixed::getRawBits(void) const
{
	return (this->value_);
}

void	Fixed::setRawBits(int const raw)
{
	this->value_ = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignement operator called\n";
	if (this == &other)
		return (*this);
	this->value_ = other.value_;
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& rhs)
{
	stream << rhs.toFloat();
	return (stream);
}
