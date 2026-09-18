#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>

class ScalarConverter {
 public:
  static void convert(const std::string& input);
 private:
  // Constuctor/Destructor
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& rhs);
  ~ScalarConverter(void);


};

#endif
