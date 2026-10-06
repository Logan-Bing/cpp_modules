#include "../includes/header.hpp"

int main()
{
	std::srand(std::time(NULL));

	Base base;
	Base *obj = base.generate();

	obj->identify(obj);
	(*obj).identify(obj);

	return 0;
}
