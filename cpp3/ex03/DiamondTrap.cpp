#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Default Constuctor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name):
	name_(name)
{
	this->hit_points_ = FragTrap::hit_points_;
	this->energy_points_ = ScavTrap::energy_points_;
	this->attack_damage_ = FragTrap::attack_damage_;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called\n";
}

int		DiamondTrap::getEnergyPoints(void) const
{
	return this->energy_points_;
}

int		DiamondTrap::getHitPoints(void) const
{
	return this->hit_points_;
}

int		DiamondTrap::getAttackDamage(void) const
{
	return this->attack_damage_;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name: " + this->name_ << " memory: " << &this->name_ << '\n';
	std::cout << "Clap name: " + this->ClapTrap::name_ << " memory: " << &this->ClapTrap::name_ << '\n';
}
