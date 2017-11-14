#ifndef D02_ZOMBIEHORDE_HPP
#define D02_ZOMBIEHORDE_HPP

#include "iostream"
#include "Zombie.hpp"


class ZombieHorde {
public:
ZombieHorde(int N);
	void announce();
	~ZombieHorde();

	void setZombies(Zombie *zombies);

private:
	Zombie *zombies;
	int n;

};


#endif
