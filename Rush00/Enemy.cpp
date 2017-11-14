#include "Enemy.hpp"

Enemy::Enemy() : Entry() {
	_charters.shape = ENEMY;
	_charters.color = 4;
	_speed = 1;
}
Enemy::Enemy(int x, int y) : Entry(x,y) {

	_charters.shape = ENEMY;
	_coord.X = x;
	_coord.Y = y;
	_charters.color = 4;
	_level = 1;
	_CHP = 1;
	_speed = 1;
	_Max_HP = 1;
	_damage = _Max_HP;
	_radius = 2;
}

Enemy::Enemy (const Enemy &val) : Entry(val)
{
	*this = val;
}

Enemy::~Enemy(){

}

void Enemy::move (int amount) {
	amount++;
	this->_coord.X--;
}