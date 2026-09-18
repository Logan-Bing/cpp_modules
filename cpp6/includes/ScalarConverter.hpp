#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>

#define DOUBLE_NAN_REPR "nan"
#define DOUBLE_INF_P_REPR "+inf"
#define DOUBLE_INF_N_REPR "-inf"

#define FLOAT_NAN_REPR "nanf"
#define FLOAT_INF_P_REPR "+inff"
#define FLOAT_INF_N_REPR "-inff"

class ScalarConverter {
 public:
  static void convert(const std::string& input);
 private:
  struct LiteralMapping
  {
	  std::string double_repr;
	  std::string float_repr;
  };

  static const LiteralMapping pseudo_literals[3];

  // helpers
  static bool handlePseudoLitteral(const std::string& input);

  /*
   * @brief Print template result + types
   */ 
  static void	printAllTypes
	(
		  const std::string& ch,
		  const std::string& i,
		  const std::string& f,
		  const std::string& d
	);
  // Constuctor/Destructor
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& rhs);
  ~ScalarConverter(void);


};

#endif
