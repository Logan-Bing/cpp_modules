#include "Harl.hpp"

Harl::Harl(void)
{
	this->_levels[0] = "DEBUG"; this->f_ptr[0] = &Harl::debug;
	this->_levels[1] = "INFO"; this->f_ptr[1] = &Harl::info;
	this->_levels[2] = "WARNING"; this->f_ptr[2] = &Harl::warning;
	this->_levels[3] = "ERROR"; this->f_ptr[3] = &Harl::error;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (level == this->_levels[i])
		{
			(this->*f_ptr[i])();
			return;
		}
	}
}
