#include "../includes/BitcoinExchange.hpp"
#include "../utils/Debug.hpp"
#include <exception>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange(void): data_(), filename_(NULL)
{
	DEBUG_MSG("BitcoinExchange Default Constuctor called\n");
}

BitcoinExchange::BitcoinExchange(std::string filename): data_(), filename_(filename){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
	DEBUG_MSG("BitcoinExchange Copy Constructor called\n");
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
	
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	DEBUG_MSG("BitcoinExchange Destructor called\n");
}

void	BitcoinExchange::iterOnStream(std::string& filename, char sep, LineHandler handler)
{
	std::ifstream stream(PROJECT_DIR "/" + filename);
	if (!stream.is_open())
		throw std::runtime_error("Failed opening file");
	for (std::string line; std::getline(stream, line);)
	{
		std::string date;
		std::string value;
		std::getline(std::stringstream(line), date, sep);
		value = line.substr(date.length() + 1, line.length() - date.length());
		(this->*handler)(date, value);
	}
}

void	BitcoinExchange::fillData(const std::string& date, const std::string& value)
{
	data_[date] = value;
}

void	BitcoinExchange::ParseCsv()
{
	iterOnStream(filename_, ',',&BitcoinExchange::fillData);
}

void	BitcoinExchange::PrintData()
{
	for (str_map::iterator it = data_.begin(); it != data_.end(); ++it)
	{
		std::cout << it->first << "=" << it->second << std::endl;
	}
}
