#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) {
	this->name = name;
	this->type = type;
	announce();
}

Zombie::Zombie() {
	this->name = random_name();
	this->type = "none";

}

void Zombie::announce ()
{
	std::cout << "<" << this->name <<" (" << this->type <<")> Braiiiiiiinnnssss...\n";
}

Zombie::~Zombie() {
	std::cout << "<" << this->name <<" (" << this->type <<")> Dead\n";
}

std::string Zombie::random_name() {
	int c;
	char *name;
	int i;
	std::string zombie_name;


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
