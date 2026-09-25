#include "../includes/header.hpp"
#include <iostream>
#include <cstdint>

int main()
{
	Data data;
	data.value = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	int equal = ptr == &data;

	std::cout << ptr << std::endl;
	std::cout << &data << std::endl;
	std::cout << equal << std::endl;

	return 0;
}
