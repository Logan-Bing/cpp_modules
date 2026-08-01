#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {
 public:
  // Constuctor/Destructor
  Cat(void);
  Cat(const Cat& other);
  Cat& operator=(const Cat& rhs);
  ~Cat(void);

  void	makeSound(void) const;

 private:

};

#endif
