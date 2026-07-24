#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d1("logan");

	d1.whoAmI();
	d1.attack("ennemy");
	return 0;
}
