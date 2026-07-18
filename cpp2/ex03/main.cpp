#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);
	Point point(10, -15);

	bsp(a, b, c, point) ? std::cout << "inside\n" : std::cout << "outside\n";
	return 0;
}
