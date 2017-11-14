//
// Created by Oleksiy Pogiba on 11/5/17.
//

#include "SpaceObject.hpp"

SpaceObject::SpaceObject() : Entry() {
	_speed = 2;
	_charters.shape = OBJECT;
	_charters.color = 7;
	_damage = 0;
}

SpaceObject::SpaceObject(int x, int y) : Entry(x,y) {
	_damage = 0;
	_speed = 2;
	_charters.shape = OBJECT;
	_charters.color = 7;
	_CHP = 1000;
}

SpaceObject::SpaceObject(const SpaceObject &val) : Entry(val)
{
	*this = val;
}
SpaceObject::~SpaceObject() {}

void SpaceObject::move (int amount) {
	amount++;
	this->_coord.X--;
}