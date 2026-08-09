#ifndef __ICE_HPP__
#define __ICE_HPP__

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice: public AMateria {
 public:
  // Constuctor/Destructor
  Ice(void);
  Ice(const Ice& other);
  Ice& operator=(const Ice& rhs);
  ~Ice(void);

  AMateria* clone() const;
  void use(ICharacter& target);
 private:

};

#endif
