#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
 public:
  // Constuctor/Destructor
  DiamondTrap(void);
  DiamondTrap(const std::string& name);
  // DiamondTrap(const DiamondTrap& other);
  // DiamondTrap& operator=(const DiamondTrap& rhs);
  ~DiamondTrap(void);

  int	getHitPoints(void) const;
  int	getEnergyPoints(void) const;
  int	getAttackDamage(void) const;
  void	whoAmI(void);

 private:
  std::string name_;

};

#endif
