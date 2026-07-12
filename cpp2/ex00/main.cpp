#include "Fixed.hpp"

int main()
{
	Fixed a;
	a.setRawBits(10);
	Fixed b;

	b = a;
	std::cout << b.getRawBits() << '\n';

	return (0);
}
