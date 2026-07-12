#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>
#define SIZE 4

class Harl {

	private:
		std::string _levels[SIZE];
		void	(Harl::*_f_ptr[SIZE])(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		void	complain(std::string level);
};

#endif
