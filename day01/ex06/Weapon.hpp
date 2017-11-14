#ifndef D02_WEAPON_HPP
#define D02_WEAPON_HPP

#include <iostream>


class Weapon {
private: std::string type;
public:
	Weapon(std::string t);
	const std::string &getType() const;
	void setType(std::string type);
};




#endif //D02_WEAPON_HPP
