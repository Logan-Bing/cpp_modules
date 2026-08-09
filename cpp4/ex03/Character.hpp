#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <ostream>

#define SLOT_SIZE 4

class Character: public ICharacter {
 private:

 typedef struct Stuff
 {
	AMateria* e;
	struct Stuff* next;
 } t_stuff;

 public:
  // Constuctor/Destructor
  Character(void);
  Character(const std::string& name);
  Character(const Character& other);
  Character& operator=(const Character& rhs);
  ~Character(void);

  // Work rules
  int validIndex(int idx) const;

  // Getter
  std::string const & getName() const;

  // Features
  void equip(AMateria* m);
  void unequip(int idx);
  virtual void use(int idx, ICharacter& target);

  // Print
  void infos();

  // Copy
  void	copySlot(const Character& other);
  void	copyStuff(const Character& other);

  // Clear
  void	clearSlot();
  void	clearStuff();

 private:
  
  std::string name_;
  AMateria* slot_[SLOT_SIZE];
  t_stuff* stuff_;
};

#endif
