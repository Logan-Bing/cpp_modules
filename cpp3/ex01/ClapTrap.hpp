#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {
 public:
	// Constuctor/Destructor
	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& rhs);
	~ClapTrap(void);

	// functions
	void	setEnergyPoints(int ep);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

 protected:
	std::string	name_;
	int			hit_points_;
	int			energy_points_;
	int			attack_damage_;
};

#endif

