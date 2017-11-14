//
// Created by Oleksiy Pogiba on 11/5/17.
//

#include "Medical_help.hpp"

Medical_help ::Medical_help() : Entry() {
	_speed = 1;
	_charters.shape = MEDICAL;
	_charters.color = 5;
}

Medical_help::Medical_help(int x, int y) : Entry(x,y) {
	_speed = 1;
	_charters.shape = MEDICAL;
	_charters.color = 5;
	_radius = 1;
	_damage = -1;
}

Medical_help::Medical_help(const Medical_help &val) : Entry(val)
{
	*this = val;
}
Medical_help::~Medical_help() {}

void Medical_help::move (int amount) {
	amount++;
	this->_coord.X--;
}