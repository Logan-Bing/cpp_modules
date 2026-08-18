#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <ostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

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
  Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);
  Form(const Form& other);
  Form& operator=(const Form& rhs);
  ~Form(void);

  // getters
  const std::string& getName() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExecute() const;
  bool getSignedStatus() const;

  // checker
  void	gradeChecker_(int grade);

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
