#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include <ostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
 public:
  class FormNotSignedException: public std::invalid_argument {
		public:
		 FormNotSignedException(const std::string& err);
  };

  class GradeTooHighException: public std::invalid_argument {
	  public:
	    GradeTooHighException(const std::string& err);
  };

  class GradeTooLowException: public std::invalid_argument {
	  public:
	    GradeTooLowException(const std::string& err);
  };
  // Constuctor/Destructor
  AForm(void);
  AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);
  AForm(const AForm& other);
  AForm& operator=(const AForm& rhs);
  virtual ~AForm(void);

  // getters
  const std::string& getName() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExecute() const;
  bool getSignedStatus() const;

  // featurs
  void	beSigned(const Bureaucrat& b);
  void	execute(const Bureaucrat& executor) const;
  virtual const std::string& getTarget() const = 0;

 protected:
  virtual void	executeAction() const = 0;

 private:
  void	gradeChecker_(int grade);
  void	formChecker_(const Bureaucrat& b) const;

  const std::string name_;
  const int gradeRequiredToSign_;
  const int gradeRequiredToExecute_;
  bool is_signed;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif
