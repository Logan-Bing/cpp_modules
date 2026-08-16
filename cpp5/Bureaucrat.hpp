#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "Debug.hpp"

class Bureaucrat {
 public:
  class GradeTooHighException: public std::exception {};
  class GradeTooLowException: public std::exception {};
  // Constuctor/Destructor
  Bureaucrat(void);
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& rhs);
  ~Bureaucrat(void);

  const std::string& getName(void) const;
  int getGrade(void) const;
  int	gradeChecker_(int grade);
  void	increment();
  void	decrement();

 private:
  const std::string name_;
  int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif

