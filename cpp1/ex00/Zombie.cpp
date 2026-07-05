#include "Zombie.hpp"

Zombie::Zombie(const std::string& name): _name(name){}

Zombie::~Zombie(void)
{
	std::cout << this->_name + " get destroyed"<< '\n';
}

void	Zombie::announce(void)
{
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ...\n";
}
