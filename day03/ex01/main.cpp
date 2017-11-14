#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	FragTrap alex ("Alex");
	FragTrap vasya (alex);

	alex.rangedAttack("Robot number 1");
	alex.meleeAttack("Robot number 2");
	alex.beRepaired(10);
	alex.takeDamage(90);
	alex.vaulthunter_dot_exe("Robot  number 2");
	alex.beRepaired(10);
	alex.takeDamage(120);

	std::cout << std::endl;;
	vasya.beRepaired(10);
	vasya.takeDamage(90);
	vasya.takeDamage(5);
	vasya.vaulthunter_dot_exe("Robot  number 2");

	std::cout << std::endl;;

	ScavTrap alex1 ("AlexScav");
	ScavTrap vasya1 (alex1);

	alex1.rangedAttack("Robot number 1");
	alex1.meleeAttack("Robot number 2");
	alex1.beRepaired(10);
	alex1.takeDamage(90);
	alex1.challengeNewcomer();
	alex1.challengeNewcomer();
	alex1.challengeNewcomer();
	alex1.beRepaired(10);
	alex1.takeDamage(120);

	std::cout << std::endl;;

	vasya1.beRepaired(10);
	vasya1.takeDamage(90);
	vasya1.takeDamage(5);
	vasya1.challengeNewcomer();;


	return 0;
}