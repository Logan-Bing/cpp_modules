#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap {
 public:
  // Constuctor/Destructor
  FragTrap(void);
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& rhs);
  ~FragTrap(void);

  // Functions
  void	highFivesGuys(void);
  // attributes

 private:

};

#endif
