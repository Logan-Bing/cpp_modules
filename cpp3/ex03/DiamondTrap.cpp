#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Default Constuctor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name):
	ClapTrap(name + "_clap_name"),
	name_(name)
{
	this->energy_points_ = SCAVTRAP_EP;
	this->hit_points_ = FRAGTRAP_HP;
	this->attack_damage_ = FRAGTRAP_AD;
	std::cout << "DiamondTrap Default Constuctor with name called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	name_(other.name_)
{
	std::cout << "DiamondTrap Copy Constuctor with name called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		this->hit_points_ = rhs.hit_points_;
		this->energy_points_ = rhs.energy_points_;
		this->attack_damage_ = rhs.attack_damage_;
		this->name_ = rhs.name_;
		this->ClapTrap::name_ = rhs.ClapTrap::name_;
	}
	return *this;
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

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name: " + this->name_ << "\n\t";
	std::cout << "Clap name: " + this->ClapTrap::name_ << "\n";
}
