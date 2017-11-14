//
// Created by Oleksiy Pogiba on 11/4/17.
//

#include "Entry.hpp"

Entry::Entry() {
	_name = "Default";
	_charters.shape = ENTRY;
	_coord.X = 0;
	_coord.Y = 0;
	_charters.color = 1;
	_level = 1;
	_Max_HP = 1;
	_CHP = _Max_HP;
	_damage = 0;
	_speed = 0;
	_radius = 0;
}


Entry::Entry(std::string name , int x, int y) {

	_name = name;
	_charters.shape = ENTRY;
	_coord.X = x;
	_coord.Y = y;
	_charters.color = 1;
	_level = 1;
	_Max_HP = 1;
	_CHP = _Max_HP;
	_damage = 0;
	_radius = 0;
	_speed = 0;
}

Entry::Entry(int x, int y) {

	_name = "Default";
	_charters.shape = ENTRY;
	_coord.X = x;
	_coord.Y = y;
	_charters.color = 1;
	_level = 1;
	_Max_HP = 1;
	_CHP = _Max_HP;
	_damage = 0;
	_radius = 0;
	_speed = 0;
}

Entry::Entry (const Entry &val)
{
	*this = val;
}

Entry& Entry::operator=(const Entry &val) {
	if (this == &val)
		return *this;
	_name = val._name;
	_coord = val._coord;
	_level = val._level;
	_Max_HP = val._Max_HP;
	_CHP = val._CHP;
	_damage = val._damage;
	_speed = val._speed;
	_charters = val._charters;
	_radius = val._radius;
	return (*this);
}

Entry& Entry::operator+=(int val) {
	this->_CHP += val;

	return (*this);
}

Entry& Entry::operator-=(int val) {

	this->_CHP -= val;

	return (*this);
}

void Entry::level_up()
{
	this->_level++;
	this->_Max_HP++;
	this->_CHP = this->_Max_HP;
	this->_damage = this->_CHP;
	this->_speed++;
}


void Entry::move_down(int count) {
	_coord.Y = _coord.Y - count;
}

void Entry::move_up(int count) {
	_coord.Y = _coord.Y + count;
}

void Entry::move_left(int count) {
	_coord.X = _coord.X - count;
}

void Entry::move_right(int count) {
	_coord.X = _coord.X + count;
}


void Entry::takeDamage(int amount) {
	this->_CHP -= amount;
}

void Entry::move(int amount)
{
	amount++;
}

int	Entry::get_index(void) const{
	return (-1);
}





















































Entry::~Entry() {

}




int Entry::get_Max_HP() const {
	return _Max_HP;
}

const std::string &Entry::get_name() const {
	return _name;
}

int Entry::get_level() const {
	return _level;
}

int Entry::get_damage() const {
	return _damage;
}


int Entry::get_CHP() const {
	return _CHP;
}

int Entry::get_radius() const {
	return _radius;
}

int Entry::get_speed() const {
	return _speed;
}

const _event &Entry::get_coord() const {
	return _coord;
}

const _characters &Entry::get_charters() const {
	return _charters;
}

void Entry::set_coord(const _event &_coord) {
	Entry::_coord = _coord;
}


//_name = "Entry " + std::to_string(_Index + 1);

