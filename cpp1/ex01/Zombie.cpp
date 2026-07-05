#include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::Zombie(const std::string& name): _name(name){}

void	Zombie::announce(void)
{
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(const std::string& name)
{
	this->_name = name;
}
