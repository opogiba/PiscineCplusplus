#include "Human.hpp"

void Human::intimidatingShout(std::string const &target) {
	std::cout << "intimidatingShout " << target << "\n";
}

void Human::meleeAttack(std::string const &target) {
	std::cout << "meleeAttack " << target << "\n";
}

void Human::rangedAttack(std::string const &target) {
	std::cout << "rangedAttack " << target << "\n";
}

void Human::action(std::string const &action_name, std::string const &target) {
	int i;

	i = 0;
	std::string mas[3]= {"intimidating", "melee", "ranged"};
	void (Human::*ptr[3])(std::string const &) = {
			&Human::intimidatingShout,
			&Human::meleeAttack,
			&Human::rangedAttack
	};
	while (i < 3)
	{
		if(mas[i] == action_name)
			(this->*ptr[i])(target);
		i++;
	}


}