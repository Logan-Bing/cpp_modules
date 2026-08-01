#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
 public:
  // Constuctor/Destructor
  Dog(void);
  Dog(const Dog& other);
  Dog& operator=(const Dog& rhs);
  ~Dog(void);

  void	makeSound(void) const;
 private:

};

#endif
