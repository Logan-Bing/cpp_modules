#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "INIT\n";
	std::cout << "\t"; DiamondTrap trap_1;
	std::cout << "\t"; DiamondTrap trap_2("Trap");
	std::cout << "\t"; DiamondTrap trap_3(trap_2);
	std::cout << "--\n";

	std::cout << "ASSIGNEMENT TESTS\n";
	std::cout << "\t"; trap_3.whoAmI();
	std::cout << "\t"; std::cout << "EP: " << trap_2.getEnergyPoints() <<  "\n";
	std::cout << "\t"; std::cout << "HP: " << trap_2.getHitPoints() <<  "\n";
	std::cout << "\t"; std::cout << "AD: " << trap_2.getAttackDamage() <<  "\n";
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
	std::cout << "--\n";

	std::cout << "DESTRUCTOR\n";

	return 0;
}
