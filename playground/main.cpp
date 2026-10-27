#include <exception>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>


int main()
{
	double d = std::numeric_limits<double>::max();

	std::cout << d << std::endl;
}
