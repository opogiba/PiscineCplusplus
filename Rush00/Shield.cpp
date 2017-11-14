//
// Created by Oleksiy Pogiba on 11/5/17.
//

#include "Shield.hpp"

Shield ::Shield() : Entry() {
	_speed = 1;
	_charters.shape = SHIELD;
	_charters.color = 6;
}

Shield::Shield(int x, int y) : Entry(x,y) {
	_speed = 1;
	_charters.shape = SHIELD;
	_charters.color = 6;
	_radius = 1;
	_damage = -3;
}

Shield::Shield(const Shield &val) : Entry(val)
{
	*this = val;
}
Shield::~Shield() {

}
void Shield::move (int amount) {
	amount++;
	this->_coord.X--;
}