#include <iostream>
#include "Zombie.hpp"


int main ()
{
	Zombie *z = newZombie("Heap Zombie");
	z->announce();
	randomChump("Stack Zombie");

	delete z;
	return (0);
}
