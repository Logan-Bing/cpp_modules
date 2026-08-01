#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {
 public:
  // Constuctor/Destructor
  Animal(void);
  Animal(const Animal& other);
  Animal& operator=(const Animal& rhs);
  virtual ~Animal(void);

  virtual void	makeSound(void) const;
  const std::string&	getType(void) const;

 protected:
  std::string type_;

};

#endif
