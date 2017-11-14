#include "Weapon.hpp"
#include <iostream>

#ifndef D02_HUMANB_HPP
#define D02_HUMANB_HPP


class HumanB {
private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanB(std::string name);
	void attack();
	void setWeapon(Weapon &weapon1);

};


#endif //D02_HUMANB_HPP
