#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name): _name(name) {}

void	HumanB::attack(void)
{
	std::cout << this->_name + " attacks with their " + this->_weapon->getType() + '\n';
}

void	HumanB::setWeapon(Weapon weapon)
{
	*this->_weapon = weapon;
}
