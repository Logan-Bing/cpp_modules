#include <exception>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>


int main()
{
	try
	{
		throw std::runtime_error("boom");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
