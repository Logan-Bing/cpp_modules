#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
 public:
  // Constuctor/Destructor
  WrongCat(void);
  WrongCat(const WrongCat& other);
  WrongCat& operator=(const WrongCat& rhs);
  ~WrongCat(void);

  void	makeSound(void) const;

 private:

};

#endif
