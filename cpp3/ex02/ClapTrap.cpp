#include "ClapTrap.hpp"
#include <sstream>
#include <string>

ClapTrap::ClapTrap(void):
	name_(""),
	hit_points_(10),
	energy_points_(10),
	attack_damage_(0)
{
	std::cout << "ClapTrap Default Constuctor called\n\t";
}

ClapTrap::ClapTrap(const std::string name):
	name_(name),
	hit_points_(10),
	energy_points_(10),
	attack_damage_(0)
{
	std::cout << "ClapTrap Constuctor with name called\n\t";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy Constuctor called\n\t";
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	// Protection (surtout utilile quand on utilise la heap)
	/*
	 * delete this->value_
	 * this->value = rhs.value_ (rhs.value_) n'existe plus !
	*/
	std::cout << "ClapTrap copy operator called\n\t";
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
	std::cout << "Set energy points at " << ep + '\n';
	this->energy_points_ = ep;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points_ < 1)
	{
		std::cout << "Not enough energy points\n";
		return ;
	}

	if (hit_points_ <= 0)
	{
		std::cout << this->name_ + " is dead\n";
		return ;
	}

	this->energy_points_--;
	std::cout << "ClapTrap " + this->name_ + " attacks " + target + ", causing " << this->attack_damage_<< " points of damage !\n\t";
	std::cout << "EnergyPoints(" + this->name_ + "):" << this->energy_points_ << '\n';
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points_ <= 0)
	{
		std::cout << this->name_ + " is dead\n";
		return ;
	}

	amount > static_cast<unsigned int>(this->hit_points_) ? this->hit_points_ = 0 : this->hit_points_ -= amount;
	std::cout << "ClapTrap " + this->name_ + " take " << amount << " damage !\n\t";
	std::cout << "LifePoints(" + this->name_ + "):" << this->hit_points_ << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points_ < 1)
	{
		std::cout << "Not enough energy points\n";
		return ;
	}
	
	if (hit_points_ <= 0)
	{
		std::cout << this->name_ + " is dead\n";
		return ;
	}

	this->hit_points_ += amount;
	this->energy_points_--;

	std::cout << "ClapTrap " + this->name_ + " repairs itself " << amount << " points !\n\t";
	std::cout << "LifePoints(" + this->name_ + "):" << this->hit_points_ << "\n\t";
	std::cout << "EnergyPoints(" + this->name_ + "):" << this->energy_points_ << '\n';
}
