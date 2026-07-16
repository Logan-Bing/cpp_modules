#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <ostream>


class Fixed {
 public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed& other);
	~Fixed(void);
	Fixed &operator=(const Fixed& other);
	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

 private:
	int	value_;
	static const int FRACTIONAL_BITS = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
