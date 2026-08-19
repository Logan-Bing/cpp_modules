#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
 public:
  // Constuctor/Destructor
  PresidentialPardonForm(void);
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
  ~PresidentialPardonForm(void);

  void	execute(const Bureaucrat& executor) const;
 private:
  const std::string target_;

};

#endif
