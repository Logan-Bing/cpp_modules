#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap {
 public:
  // Constuctor/Destructor
  ScavTrap(void);
  ScavTrap(const std::string&);
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& rhs);
  ~ScavTrap(void);

  void	attack(const std::string& target);
  void	guardGate();
  // attributes

 private:

};

#endif
