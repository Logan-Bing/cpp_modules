#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Default Constuctor called\n";
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
	std::cout << "ScavTrap Constuctor with name called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constuctor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap copy operator called\n";
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_points_ < 1)
	{
		std::cout << "Not enougth energy points\n";
		return ;
	}

	if (hit_points_ <= 0)
	{
		std::cout << this->name_ + " is dead\n";
		return ;
	}

	this->energy_points_--;
	std::cout << "ScavTrap " + this->name_ + " attacks " + target + ", causing " + std::to_string(this->attack_damage_) + " points of damage !\n";
	std::cout << "EnergyPoints(" + this->name_ + "):" + std::to_string(this->energy_points_) + '\n';
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->name_ + " is now int Gate keeper mode !\n";
}
