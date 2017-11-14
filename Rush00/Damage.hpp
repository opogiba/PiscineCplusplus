//
// Created by Oleksiy Pogiba on 11/5/17.
//

#ifndef RUSH00_DAMAGE_HPP
#define RUSH00_DAMAGE_HPP

#include "Entry.hpp"

class Damage : public Entry {
protected:
	Damage();
public:
	Damage(int x, int y);
	Damage (const Damage &val);
	~Damage();
	void move (int);
};

#endif //RUSH00_DAMAGE_HPP
