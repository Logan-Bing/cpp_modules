#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal {
 public:
  // Constuctor/Destructor
  WrongAnimal(void);
  WrongAnimal(const WrongAnimal& other);
  WrongAnimal& operator=(const WrongAnimal& rhs);
  ~WrongAnimal(void);

  void	makeSound(void) const;
  const std::string&	getType(void) const;

 protected:
  std::string type_;

};

#endif
