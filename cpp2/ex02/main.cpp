#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// ADDITION
	Fixed x(10);
	std::cout << "LIGNE 17: " << x + x << std::endl;
	// SOUSTRATCION
	std::cout << "LIGNE 19: " << x - x << std::endl;
	// DIVISION
	std::cout << "LIGNE 22: " << x / 2 << std::endl;
	// Comparaison
	std::cout << "LIGNE 23: " << (x != 10) << std::endl;
	std::cout << "LIGNE 24: " << (x != 20) << std::endl;
	std::cout << "LIGNE 25: " << (x <= 10) << std::endl;
	std::cout << "LIGNE 26: " << (x < 10) << std::endl;
	std::cout << "LIGNE 27: " << (x >= 10) << std::endl;
	std::cout << "LIGNE 28: " << (x > 10) << std::endl;

	return 0;
}
