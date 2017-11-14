//
// Created by Oleksiy Pogiba on 10/31/17.
//

#ifndef D02_ZOMBIE_HPP
#define D02_ZOMBIE_HPP


#include <iostream>

class Zombie {
private: std::string name;
	std::string type;
public: void announce();
	Zombie(std::string name, std::string type);
	~Zombie();
	std::string random_name();
	Zombie();



};


#endif