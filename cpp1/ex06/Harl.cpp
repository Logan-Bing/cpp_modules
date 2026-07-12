#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	this->_levels[0] = "DEBUG"; this->_f_ptr[0] = &Harl::debug;
	this->_levels[1] = "INFO"; this->_f_ptr[1] = &Harl::info;
	this->_levels[2] = "WARNING"; this->_f_ptr[2] = &Harl::warning;
	this->_levels[3] = "ERROR"; this->_f_ptr[3] = &Harl::error;
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	int x = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (level == this->_levels[i])
		{
			x = i + 1;
			break;
		}
	}

	switch (x)
	{
		case 1:
			(this->*_f_ptr[0])();
			std::cout << '\n';
			//fall through
		case 2:
			(this->*_f_ptr[1])();
			std::cout << '\n';
			//fall through
		case 3:
			(this->*_f_ptr[2])();
			std::cout << '\n';
			//fall through
		case 4:
			(this->*_f_ptr[3])();
			std::cout << '\n';
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]";
	}
}
