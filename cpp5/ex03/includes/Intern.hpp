#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"

typedef AForm* (*FormConstructor)(const std::string& target);

class Intern {
 public:
  // Constuctor/Destructor
  Intern(void);
  Intern(const Intern& other);
  Intern& operator=(const Intern& rhs);
  ~Intern(void);

  AForm* makeForm(const std::string& form, const std::string& target);

 private:
  struct Form
  {
	std::string name;
	FormConstructor constructor;
  };

  static const Form forms[NB_OF_FORM];
};

#endif
