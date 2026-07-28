#include "ScavTrap.hpp"

int main()
{
	std::cout << "INIT\n";
	std::cout << "\t"; ScavTrap trap_1;
	std::cout << "\t"; ScavTrap trap_2("Trap");
	std::cout << "\t"; ScavTrap trap_3(trap_2);
	std::cout << "\t"; trap_1 = trap_2;
	std::cout << "--\n";

	// Basic tests
	std::cout << "BASIC TEST\n";
	std::cout << "\t"; trap_1.attack("Ennemy");
	std::cout << "\t"; trap_1.takeDamage(4);
	std::cout << "\t"; trap_1.beRepaired(10);
	std::cout << "--\n";

	std::cout << "NOT ENOUGH POINTS TESTS\n";
	std::cout << "\t"; trap_2.attack("Ennemy");
	std::cout << "\t"; trap_2.setEnergyPoints(0);
	std::cout << "\t"; trap_2.attack("Ennemy");
	std::cout << "--\n";

	std::cout << "DEAD TESTS\n";
	std::cout << "\t"; trap_3.takeDamage(100);
	std::cout << "\t"; trap_3.attack("Ennemy");
	std::cout << "\t"; trap_3.beRepaired(100);
	std::cout << "--\n";

	std::cout << "MORE TESTS\n";
	std::cout << "\t"; trap_1.guardGate();

	std::cout << "DESTRUCTOR\n";
	return 0;
}
