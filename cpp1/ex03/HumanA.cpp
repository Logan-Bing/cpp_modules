#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon): _name(name), _weapon(weapon) {}

void	HumanA::attack(void)
{
	std::cout << this->_name + " attacks with their " + this->_weapon.getType() + '\n';
}
