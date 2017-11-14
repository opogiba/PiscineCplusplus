#include "Pony.hpp"

Pony::Pony(std::string name, std::string owner, int index) {
	this->name = name;
	this->numer = index;
	this->owner = owner;
	std::cout << "Pony is born\n";
	std::cout << "Pony name - " << name << " Pony's owner - " << owner << " Pony's numer - " << index << "\n\n";
}

Pony::~Pony() {
	std::cout << "Pony is dead\n";
}
