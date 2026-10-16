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

typedef std::map<std::string, std::string> str_map;

class BitcoinExchange {
 public:
   typedef void	(BitcoinExchange::*LineHandler)(const std::string&, const std::string&);

  // Constuctor/Destructor
  BitcoinExchange(void);
  BitcoinExchange(std::string filename);
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& rhs);
  ~BitcoinExchange(void);

  void	ParseCsv();
  void	PrintData();


 private:
  void	iterOnStream(std::string& filename, char sep, LineHandler handler);
  void	fillData(const std::string& date, const std::string& value);

  str_map 		data_;
  std::string 	filename_;
};

#endif
