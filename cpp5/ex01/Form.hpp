#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

class Form {
 public:
  class GradeTooHighException: public std::invalid_argument {
	  public:
	    GradeTooHighException(const std::string& err);
  };

  class GradeTooLowException: public std::invalid_argument {
	  public:
	    GradeTooLowException(const std::string& err);
  };
  // Constuctor/Destructor
  Form(void);
  Form(const Form& other);
  Form& operator=(const Form& rhs);
  ~Form(void);

  // getters
  const std::string& getName() const;
  const int getGradeRequiredToSign() const;
  const int getGradeRequiredToExecute() const;
  const bool getSignedStatus() const;

  // featurs
  void	beSigned(const Bureaucrat& b);
 private:
  const std::string name_;
  const int gradeRequiredToSign_;
  const int gradeRequiredToExecute_;
  bool is_signed;
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif
