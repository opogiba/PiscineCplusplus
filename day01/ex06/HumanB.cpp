#include "HumanB.hpp"

HumanB::HumanB (std::string name) {
	_name = name;

}
void HumanB::attack() {
	std::cout << _name << " attacks with his " << _weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon1) {
	this->_weapon = &weapon1;
}
