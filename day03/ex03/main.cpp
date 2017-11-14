#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main() {
	FragTrap alex ("Alex");
	ScavTrap alex1 ("Alexcav");
	NinjaTrap alex2 ("dasda");
	NinjaTrap alex3 ("dasda1111");

	alex2.ninjaAttack(alex);
	alex2.ninjaAttack(alex1);
	alex3.takeDamage(35);
	alex2.ninjaAttack(alex3);

//	vasya1.challengeNewcomer();;


	return 0;
}