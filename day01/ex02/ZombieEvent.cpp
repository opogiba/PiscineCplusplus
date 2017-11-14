#include "ZombieEvent.hpp"

Zombie* ZombieEvent::newZombie(std::string name) {
	std::cout <<"Random zombie born in heap\n";
	Zombie *New = new Zombie(name,this->type);
	return (New);
}

void ZombieEvent::SetZombieType(std::string type)
{
	this->type = type;
}

void ZombieEvent::randomChump() {
	std::cout <<"Random zombie born in stack\n";
	Zombie New(random_name(), this->type);
}

std::string ZombieEvent::random_name() {
	int c;
	char *name;
	int i;
	std::string zombie_name;

	srand(clock());
	c = rand() % 5 + 5;
	name = new char[c];
	i = 0;
	while (i < c) {
		name[i] = char(rand() % 26 + 65);
		i++;
	}
	name[i] = '\0';
	zombie_name = name;

	delete(name);
	return (zombie_name);

}
