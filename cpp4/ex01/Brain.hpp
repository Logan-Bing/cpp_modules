#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

#define SIZE_IDEAS 100

class Brain {
 public:
  // Constuctor/Destructor
  Brain(void);
  Brain(const Brain& other);
  Brain& operator=(const Brain& rhs);
  ~Brain(void);

 private:
  std::string ideas[SIZE_IDEAS];

};

#endif
