//
// Created by Oleksiy Pogiba on 11/4/17.
//
#include "Entry.hpp"

#ifndef RUSH00_ENEMY_HPP
#define RUSH00_ENEMY_HPP


class Enemy : public Entry {
protected:
	Enemy();
public:
	
	Enemy (const Enemy &val);
	Enemy(int x, int y);
	void move (int amount);

	~Enemy();
};


#endif //RUSH00_ENEMY_HPP
