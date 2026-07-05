#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {

	private:
		std::string _name;
		Weapon*		_weapon;

	public:
		HumanB(const std::string& name);
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);
};

#endif
