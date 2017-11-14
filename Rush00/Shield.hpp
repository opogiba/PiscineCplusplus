//
// Created by Oleksiy Pogiba on 11/5/17.
//

#include "Entry.hpp"

#ifndef RUSH00_SHIELD_HPP
#define RUSH00_SHIELD_HPP


class Shield : public Entry {
protected:
	Shield();
public:
	Shield(int x, int y);
	Shield (const Shield &val);
	~Shield();
	void move(int count);

};




#endif //RUSH00_SHIELD_HPP
