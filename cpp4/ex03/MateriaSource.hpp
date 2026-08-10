#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Debug.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
 public:
  // Constuctor/Destructor
  MateriaSource(void);
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& rhs);
  ~MateriaSource(void);

  AMateria* createMateria(std::string const & type);
  void learnMateria(AMateria*);
  void	infos();

 private:
  AMateria* materias_[SLOT_SIZE];

};

#endif
