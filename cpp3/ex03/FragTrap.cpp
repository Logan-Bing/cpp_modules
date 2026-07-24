#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap Default Constuctor called\n";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_damage_ = 30;
	std::cout << "FragTrap Constuctor with name called\n";
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap Copy Constuctor called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap copy operator called\n";
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called\n";
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name_ << " demande un high five ! ✋" << std::endl;
}
