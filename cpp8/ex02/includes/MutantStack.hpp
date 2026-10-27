#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
 public:
  // Constuctor/Destructor
  MutantStack(void);
  MutantStack(const MutantStack& other);
  MutantStack& operator=(const MutantStack& rhs);
  ~MutantStack(void);

  typedef typename std::stack<T>::container_type::iterator iterator;

 private:

};

#include "MutantStack.tpp"

#endif
