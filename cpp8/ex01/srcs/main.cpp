#include "../includes/header.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main()
{
	int seed[] = {1,10,20,30,100,1000000000};
	int size = sizeof(seed) / sizeof(int);


	ints_v nums(seed, seed + size);
	Span s(size);
	s.addNumbers(nums.begin(), nums.end());
	s.printElements();

	return 0;
}
