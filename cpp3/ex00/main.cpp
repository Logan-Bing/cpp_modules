#include "ClapTrap.hpp"

int main()
{
	ClapTrap trap_1;
	ClapTrap trap_2("Trap");
	ClapTrap trap_3(trap_2);

	trap_1 = trap_2;

	trap_1.attack("Ennemy");
	trap_1.takeDamage(16);
	trap_1.beRepaired(3);
	trap_1.attack("Ennemy");
	trap_1.beRepaired(3);
	trap_1.attack("Ennemy");
	trap_1.beRepaired(3);
	trap_1.attack("Ennemy");
	trap_1.beRepaired(3);
	trap_1.attack("Ennemy");
	trap_1.beRepaired(3);
	trap_1.attack("Ennemy");
	return 0;
}
