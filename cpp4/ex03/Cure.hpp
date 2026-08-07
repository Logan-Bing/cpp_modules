#ifndef __CURE_HPP__
#define __CURE_HPP__

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure: public AMateria {
 public:
  // Constuctor/Destructor
  Cure(void);
  Cure(const Cure& other);
  Cure& operator=(const Cure& rhs);
  ~Cure(void);

  AMateria* clone() const;
  void use(ICharacter& target);
 private:

};

#endif
