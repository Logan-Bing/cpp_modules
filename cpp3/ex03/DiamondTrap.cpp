#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Default Constuctor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name):
	ClapTrap(name),
	name_(name)
{
	this->hit_points_ = FragTrap::hit_points_;
	this->energy_points_ = ScavTrap::energy_points_;
	this->attack_damage_ = FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): name_(other.name_){}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name: " + this->name_ << " memory: " << &this->name_ << '\n';
	std::cout << "Clap name: " + this->ClapTrap::name_ << " memory: " << &this->ClapTrap::name_ << '\n';
}
