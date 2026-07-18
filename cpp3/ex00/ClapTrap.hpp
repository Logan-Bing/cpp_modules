#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {
 public:
	// Factory functions


	// Constuctor/Destructor
	ClapTrap(void);
	ClapTrap(ClapTrap& other);
	ClapTrap& operator=(ClapTrap& rhs);
	~ClapTrap(void);

 private:
};

#endif

