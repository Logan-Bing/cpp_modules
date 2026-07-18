#include "Fixed.hpp"

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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}

int	Fixed::operator<(const Fixed& rhs) const
{
	return (this->value_ < rhs.getRawBits());
}

int	Fixed::operator>(const Fixed& rhs) const
{
	return (this->value_ > rhs.getRawBits());
}

int	Fixed::operator==(const Fixed& rhs) const
{
	return (this->value_ == rhs.getRawBits());
}

int	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->value_ >= rhs.getRawBits());
}

int	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->value_ <= rhs.getRawBits());
}

int	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->value_ != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return Fixed((this->value_ + rhs.value_));
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return Fixed((this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return Fixed((this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return Fixed((this->value_ / rhs.value_));
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	this->value_++;
	return old;
}

Fixed& Fixed::operator++(void)
{
	++this->value_;
	return *this;
}

Fixed		Fixed::operator--(int)
{
	Fixed old = *this;
	operator--();
	return old;
}

Fixed&		Fixed::operator--(void)
{
	--this->value_;
	return *this;
}

Fixed::Fixed(void): value_(0)
{
}

Fixed::Fixed(const int v): value_(v << FRACTIONAL_BITS)
{
}

Fixed::Fixed(const float v)
{
	this->value_ = static_cast<int>(roundf(v *(1 << FRACTIONAL_BITS)));
}

Fixed::Fixed(const Fixed& other): value_(other.value_)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return (*this);
	this->value_ = other.value_;
	return (*this);
}

Fixed::~Fixed(void)
{
}

std::ostream& operator<<(std::ostream& stream, const Fixed& rhs)
{
	stream << rhs.toFloat();
	return (stream);
}
