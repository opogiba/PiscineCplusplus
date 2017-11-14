#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon1) : _weapon(weapon1) {
	_name = name;

}
void HumanA::attack() {
	std::cout << _name << "attacks with his " << _weapon.getType() << "\n";
}


