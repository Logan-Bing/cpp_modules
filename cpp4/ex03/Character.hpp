#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

#define SLOT_SIZE 4

class Character: public ICharacter {
 private:

 typedef struct Garbage
 {
	AMateria* e;
	struct Garbage* next;
 } t_garbage;

 public:
  // Constuctor/Destructor
  Character(void);
  Character(const std::string& name);
  Character(const Character& other);
  Character& operator=(const Character& rhs);
  ~Character(void);

  int validIndex(int idx) const;

  std::string const & getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  virtual void use(int idx, ICharacter& target);

 private:
  
  std::string name_;
  AMateria* slot_[SLOT_SIZE];
  t_garbage* garbage;
};

#endif
