#include <iostream>
#include "Zombie.hpp"

int main ()
{
	Zombie *z = zombieHorde(10, "Jhon");

	for (int i = 0; i < 10; i++)
		z[i].announce();

	delete []z;
	return (0);
}
