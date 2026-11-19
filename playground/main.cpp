#include <climits>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>


int main()
{
	int max = INT_MAX;
	int min = INT_MIN;

	unsigned int x = max - min;

	std::cout << x;
	return 0;
}
