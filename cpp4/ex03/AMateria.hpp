#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>

class ICharacter;

class AMateria {
 protected:
  std::string type_;

 public:
  // Constuctor/Destructor
  AMateria(void);
  AMateria(const std::string& type);
  AMateria(const AMateria& other);
  AMateria& operator=(const AMateria& rhs);
  virtual ~AMateria(void);

  const std::string& getType() const;

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif
