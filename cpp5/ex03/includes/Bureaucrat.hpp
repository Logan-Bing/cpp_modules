#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <ostream>
#include <stdexcept>
#include <string>

#define GRADE_RULES "ERROR: Grade need to be between 1 and 150"

class AForm;

class Bureaucrat {
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
  Bureaucrat(void);
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& rhs);
  ~Bureaucrat(void);

  // getters
  const std::string& getName(void) const;
  int getGrade(void) const;

  // checker
  int gradeChecker_(int grade);

  // features
  void	increment();
  void	decrement();
  void	signForm(AForm& f);
  void	executeForm(const AForm& f);

 private:
  const std::string name_;
  int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
