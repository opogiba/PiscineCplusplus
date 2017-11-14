#include "ZombieEvent.hpp"

int  main()
{
	ZombieEvent *ze1 = new ZombieEvent();
	ze1->randomChump();

	ze1->SetZombieType("Chudo");
	Zombie *z1 = ze1->newZombie("Ivan");

	ze1->randomChump();

	Zombie z2("pavel", "ioan");

	delete(ze1);
	delete(z1);
	return (0);
}