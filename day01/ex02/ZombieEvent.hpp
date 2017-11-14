#ifndef D02_ZOMBIEEVENT_HPP
#define D02_ZOMBIEEVENT_HPP


#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {
public:
	Zombie* newZombie(std::string name);
	void SetZombieType(std::string type);
	void randomChump();

private:
	std::string type;
	std::string random_name();

};


#endif
