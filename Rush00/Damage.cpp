//
// Created by Oleksiy Pogiba on 11/5/17.
//

#include "Damage.hpp"
#include "Entry.hpp"

Damage ::Damage() : Entry() {
	_speed = 1;
	_charters.shape = DAMAGE;
	_charters.color = 5;
}

Damage::Damage(int x, int y) : Entry(x,y) {
	_speed = 1;
	_charters.shape = DAMAGE;
	_charters.color = 5;
	_radius = 1;	
}

Damage::Damage(const Damage &val) : Entry(val)
{
	*this = val;
}
Damage::~Damage() {

}
void Damage::move (int amount) {
	amount++;
	this->_coord.X--;
}