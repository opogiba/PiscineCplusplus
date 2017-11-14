//
// Created by Oleksiy Pogiba on 10/31/17.
//

#ifndef D02_HUMAN_HPP
#define D02_HUMAN_HPP

#include "Brain.hpp"


class Human {
private:
	const Brain brain;
public:
	std::string identify() const;
	const Brain &getBrain() const;
	Human();

};


#endif //D02_HUMAN_HPP
