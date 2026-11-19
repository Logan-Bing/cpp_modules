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
	std::cout << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
	std::cout << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
}
