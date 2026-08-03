#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>
#include <ostream>

#define SIZE_IDEAS 100

class Brain {
 public:
  // Constuctor/Destructor
  Brain(void);
  Brain(const Brain& other);
  Brain& operator=(const Brain& rhs);
  ~Brain(void);

  std::string& operator[](std::size_t idx);
  const std::string& operator[](std::size_t idx) const;

 private:
  std::string ideas_[SIZE_IDEAS];

};

#endif
