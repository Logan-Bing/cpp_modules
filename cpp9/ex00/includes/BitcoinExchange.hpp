#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#ifndef PROJECT_DIR
#	error "PROJECT_DIR is not defined (add -DPROJECT_DIR=... in the Makefile)"
#endif

#define ERR_TOO_LARGE_NUMBER "too large a number."
#define ERR_NEGATIVE_NUMBER "not a positive number."

typedef std::map<std::string, std::string> str_map;

class BitcoinExchange {
 public:
   typedef void	(BitcoinExchange::*LineHandler)(const std::string&, const std::string&);

  // Constuctor/Destructor
  BitcoinExchange(void);
  BitcoinExchange(const std::string& dataFilename, const std::string& inputFilename);
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& rhs);
  ~BitcoinExchange(void);

  void	PrintData();

  void	handleDataFile();
  void	handleInputFile();

 private:
  static float	ftAtof(const std::string& str);
  static bool	handleAmountError(float amount);
  static bool	isLeapYear(int year);
  static int	dayInMonth(const std::string& month, const std::string& year);
  static bool	checkAmountFormat(const std::string& amount);
  static bool	checkYearFormat(const std::string& year);
  static bool	checkMonthFormat(const std::string& month);
  static bool	checkDayFormat(const std::string& day, const std::string& month, const std::string& year);
  static bool	isDateFormatValid(const std::string& year, const std::string& month, const std::string& day);
  void	iterOnStream(std::string& filename, const std::string& sep, LineHandler handler);
  void	fillData(const std::string& date, const std::string& rate);
  void	handleMatchLine(const std::string& date, const std::string& amountStr);

  str_map 		data_;
  std::string 	dataFilename_;
  std::string	inputFilename_;
};

#endif
