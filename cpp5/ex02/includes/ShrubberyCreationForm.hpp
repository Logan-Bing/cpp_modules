#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>

class ShrubberyCreationForm: public AForm {
 public:
  // Constuctor/Destructor
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
  ~ShrubberyCreationForm(void);

 const std::string& getTarget() const;

 protected:
   void	executeAction() const;

 private:
  std::string target_;

};

#endif
