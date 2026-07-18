#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <ostream>


class Fixed {
 public:
	// Factory functions
	int		toInt(void) const;
	int		getRawBits(void) const;
	float	toFloat(void) const;
	void	setRawBits(int const raw);

	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	// Comparison operator
	int		operator>(const Fixed& rhs) const;
	int		operator<(const Fixed& rhs) const;
	int		operator==(const Fixed& rhs) const;
	int		operator>=(const Fixed& rhs) const;
	int		operator<=(const Fixed& rhs) const;
	int		operator!=(const Fixed& rhs) const;

	// arithmetic operators
	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator*(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;

	// increment/decrement operator
	Fixed	operator++(int);
	Fixed&	operator++(void);
	Fixed	operator--(int);
	Fixed&	operator--(void);

	// Contructor / Destructor
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed& other);
	~Fixed(void);

 private:
	int	value_;
	static const int FRACTIONAL_BITS = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
