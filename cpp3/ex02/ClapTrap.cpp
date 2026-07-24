#include "ClapTrap.hpp"
#include <string>

ClapTrap::ClapTrap(void):
	name_(""),
	hit_points_(10),
	energy_points_(10),
	attack_damage_(0)
{
	std::cout << "ClapTrap Default Constuctor called\n";
}

ClapTrap::ClapTrap(const std::string name):
	name_(name),
	hit_points_(10),
	energy_points_(10),
	attack_damage_(0)
{
	std::cout << "ClapTrap Constuctor with name called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other):
	name_(other.name_),
	hit_points_(other.hit_points_),
	energy_points_(other.energy_points_),
	attack_damage_(other.attack_damage_)
{
	std::cout << "ClapTrap Copy Constuctor called\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	// Protection (surtout utilile quand on utilise la heap)
	/*
	 * delete this->value_
	 * this->value = rhs.value_ (rhs.value_) n'existe plus !
	*/
	std::cout << "ClapTrap copy operator called\n";
	if (this == &rhs)
		return *this;
	this->name_ = rhs.name_;
	this->hit_points_ = rhs.hit_points_;
	this->energy_points_ = rhs.energy_points_;
	this->attack_damage_ = rhs.attack_damage_;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called\n";
}

void	ClapTrap::setEnergyPoints(int ep)
{
	std::cout << "Set energy points at " + std::to_string(ep) + '\n';
	this->energy_points_ = ep;
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " + this->name_ + " attacks " + target + ", causing " + std::to_string(this->attack_damage_) + " points of damage !\n";
	std::cout << "EnergyPoints(" + this->name_ + "):" + std::to_string(this->energy_points_) + '\n';
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	amount > static_cast<unsigned int>(this->hit_points_) ? this->hit_points_ = 0 : this->hit_points_ -= amount;
	std::cout << "ClapTrap " + this->name_ + " take " + std::to_string(amount) + " damage !\n";
	std::cout << "LifePoints(" + this->name_ + "):" + std::to_string(this->hit_points_) + '\n';
}

void	ClapTrap::beRepaired(unsigned int amount)
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

	this->hit_points_ += amount;
	this->energy_points_--;

	std::cout << "ClapTrap " + this->name_ + " repairs itself " + std::to_string(amount) + " points !\n";
	std::cout << "LifePoints(" + this->name_ + "):" + std::to_string(this->hit_points_) + '\n';
	std::cout << "EnergyPoints(" + this->name_ + "):" + std::to_string(this->energy_points_) + '\n';
}

