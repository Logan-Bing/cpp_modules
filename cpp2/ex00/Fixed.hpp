#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
 public:
	Fixed(void);
	// Fixed(const Fixed&);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

 private:
	int	value_;
	static const int FRACTIONAL_BITS = 8;
};

#endif
