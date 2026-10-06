#include "../includes/header.hpp"

int main()
{
	Base *base = new A();

	B* b = dynamic_cast<B*>(base);

	std::cout << b << std::endl;

	return 0;
}
