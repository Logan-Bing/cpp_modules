#include "ClapTrap.hpp"

int main()
{
	std::cout << "INIT\n";
	std::cout << "\t"; ClapTrap trap_1;
	std::cout << "\t"; ClapTrap trap_2("Trap");
	std::cout << "\t"; ClapTrap trap_3(trap_2);
	std::cout << "\t"; trap_1 = trap_2;
	std::cout << "--\n";

	// Basic tests
	std::cout << "BASIC TEST\n";
	std::cout << "\t"; trap_1.attack("Ennemy");
	std::cout << "\t"; trap_1.takeDamage(4);
	std::cout << "\t"; trap_1.beRepaired(10);
	std::cout << "--\n";

	std::cout << "NOT ENOUGH POINTS TESTS\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\t";
		trap_2.attack("Ennemy");
	}
	std::cout << "\t";
	trap_2.attack("Ennemy");
	std::cout << "--\n";

	std::cout << "CLAPTRAP DEAD TESTS\n";
	std::cout << "\t"; trap_3.takeDamage(100);
	std::cout << "\t"; trap_3.attack("Ennemy");
	std::cout << "\t"; trap_3.beRepaired(100);
	std::cout << "--\n";

	std::cout << "DESTRUCTOR\n";
	return 0;
}
