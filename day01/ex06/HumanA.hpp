//
// Created by Oleksiy Pogiba on 10/31/17.
//
#include "Weapon.hpp"
#include <iostream>

#ifndef D02_HUMANA_HPP
#define D02_HUMANA_HPP


class HumanA {
private:
	std::string _name;
	Weapon &_weapon;
public:
	HumanA(std::string name, Weapon &weapon1);
	void attack();


};


#endif //D02_HUMANA_HPP
