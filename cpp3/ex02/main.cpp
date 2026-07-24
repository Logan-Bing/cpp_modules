#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "------------------ INIT ------------------\n";
	FragTrap trap_1;
	FragTrap trap_2("Trap");
	FragTrap trap_3(trap_2);
	trap_1 = trap_2;
	std::cout << "------------------ END ------------------\n";

	std::cout << '\n';

	// Basic tests
	std::cout << "------------------ BASIC TESTS ------------------\n";
	trap_1.attack("Ennemy");
	trap_1.takeDamage(4);
	trap_1.beRepaired(10);
	std::cout << "------------------ END ------------------\n";

	std::cout << '\n';

	std::cout << "------------------ NOT ENOUGH POINTS TESTS ------------------\n";
	trap_2.setEnergyPoints(0);
	trap_2.attack("Ennemy");
	std::cout << "------------------ END ------------------\n";

	std::cout << '\n';

	std::cout << "------------------ CLAPTRAP DEAD TESTS ------------------\n";
	trap_3.takeDamage(100);
	trap_3.attack("Ennemy");
	trap_3.beRepaired(100);
	std::cout << "------------------ END ------------------\n";

	return 0;
}
