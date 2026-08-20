#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm {
 public:
  // Constuctor/Destructor
  RobotomyRequestForm(void);
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
  ~RobotomyRequestForm(void);

 const std::string& getTarget() const;

 protected:
   void	executeAction() const;

 private:
  std::string target_;

};

#endif
