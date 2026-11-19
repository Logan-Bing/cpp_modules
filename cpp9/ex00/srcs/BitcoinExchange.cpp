#include "../includes/BitcoinExchange.hpp"
#include "../utils/Debug.hpp"
#include <cctype>
#include <exception>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange(void): data_(), dataFilename_(NULL), inputFilename_(NULL)
{
	DEBUG_MSG("BitcoinExchange Default Constuctor called\n");
}

BitcoinExchange::BitcoinExchange(const std::string& dataFilename, const std::string& inputFilename): data_(), dataFilename_(dataFilename), inputFilename_(inputFilename){}

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

void	BitcoinExchange::iterOnStream(std::string& filename, const std::string& sep, LineHandler handler)
{
	std::string path = std::string(PROJECT_DIR) + "/" + filename;
	std::ifstream stream(path.c_str());

	if (!stream.is_open())
		throw std::runtime_error("Failed opening file");
	for (std::string line; std::getline(stream, line);)
	{
		std::string::size_type pos = line.find(sep);
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + sep.length());

		(this->*handler)(date, value);
	}
}

void	BitcoinExchange::PrintData()
{
	for (str_map::iterator it = data_.begin(); it != data_.end(); ++it)
	{
		std::cout << it->first << "=" << it->second << std::endl;
	}
}

void	BitcoinExchange::handleDataFile()
{
	iterOnStream(dataFilename_, ",", &BitcoinExchange::fillData);
}

void	BitcoinExchange::handleInputFile()
{
	iterOnStream(inputFilename_, " | ", &BitcoinExchange::handleMatchLine);
}

float BitcoinExchange::ftAtof(const std::string& str)
{
	float x;
	std::istringstream ss(str);

	ss >> x;
	return x;
}

bool	BitcoinExchange::handleAmountError(float amount)
{
	if (amount < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (amount > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int	BitcoinExchange::dayInMonth(const std::string& month, const std::string& year)
{
	int allMonths[] =
	{
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31,
	};

	if (isLeapYear(ftAtof(year)))
		allMonths[1]++;

	return allMonths[static_cast<int>(ftAtof(month) - 1)];
}

bool BitcoinExchange::checkYearFormat(const std::string& year)
{
	return year.length() == 4 && isAllDigits(year);
}

bool BitcoinExchange::checkMonthFormat(const std::string& month)
{
	return month.length() == 2 && isAllDigits(month)
		&& month > "00" && month < "13";
}

bool	BitcoinExchange::checkAmountFormat(const std::string& amount)
{
	for (std::string::const_iterator it = amount.begin(); it != amount.end(); ++it)
	{
		if (std::isdigit(*amount.c_str()))
			return false;
	}
	return true;
}

bool BitcoinExchange::checkDayFormat(const std::string& day, const std::string& month, const std::string& year)
{
	return day.length() == 2 && isAllDigits(day)
		&& day > "00" && ftAtof(day) <= dayInMonth(month, year);
}

bool	BitcoinExchange::isDateFormatValid(const std::string& year, const std::string& month, const std::string& day)
{
	return checkYearFormat(year) && checkMonthFormat(month) && checkDayFormat(day, month, year);
}

void	BitcoinExchange::fillData(const std::string& date, const std::string& rate)
{
	data_[date] = rate;
}

void	BitcoinExchange::handleMatchLine(const std::string& date, const std::string& amountStr)
{
	if (date == "date" && amountStr == "value")
		return;

	std::string year;
	std::string month;
	std::string day;

	std::istringstream streamDate(date);

	std::getline(streamDate, year, '-');
	std::getline(streamDate, month, '-');
	std::getline(streamDate, day);

	if (!isDateFormatValid(year, month, day))
	{
		std::cout << "Error: Invalid format, expected: [YYYY-MM-DD]" << std::endl;
		return;
	}

	str_map::iterator matchedDate = data_.upper_bound(date);

	if (matchedDate == data_.end())
	{
		std::cout << "invalid" << std::endl;
		return;
	}

	if (matchedDate == data_.begin())
	{
		std::cout << "Error: bad input => " << date << " | " << amountStr << std::endl;
		return;
	}

	matchedDate--;

	if (checkAmountFormat(amountStr))
	{
		std::cout << "Error: bad input => " << date << " | " << amountStr << std::endl;
		return;
	}

	float amount = ftAtof(amountStr);

	if (!handleAmountError(amount))
		return ;

	float res = amount * ftAtof(matchedDate->second);
	std::cout << date << " => " << amountStr << " = " << res << std::endl;
}
