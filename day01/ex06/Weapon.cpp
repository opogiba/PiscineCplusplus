#include "Weapon.hpp"

Weapon::Weapon(std::string t) {
	type = t;
}
const std::string &Weapon::getType() const {
	return type;
}
void Weapon::setType(std::string type) {
	this->type = type;
}


