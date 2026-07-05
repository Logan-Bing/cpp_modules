#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name): _name(name), _weapon(NULL) {}

void	HumanB::attack(void) const
{
	if (!this->_weapon)
	{
		std::cout << this->_name + " have no weapon\n";
		return ;
	}
	std::cout << this->_name + " attacks with their " + this->_weapon->getType() + '\n';
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
