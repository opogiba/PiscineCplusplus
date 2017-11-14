//
// Created by Oleksiy Pogiba on 11/5/17.
//

#ifndef RUSH00_SPACEOBJECT_HPP
#define RUSH00_SPACEOBJECT_HPP

#include "Entry.hpp"


class SpaceObject : public Entry {

	protected:
		SpaceObject();
	public:
		SpaceObject(int x, int y);
		SpaceObject (const SpaceObject &val);
		~SpaceObject();
		void move (int);

};


#endif //RUSH00_SPACEOBJECT_HPP
