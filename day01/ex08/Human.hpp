//
// Created by Oleksiy Pogiba on 11/1/17.
//

#ifndef D02_HUMAN_HPP
#define D02_HUMAN_HPP

#include "iostream"


class Human {
private:

	void rangedAttack(std::string const & target);
	void intimidatingShout(std::string const & target);
	void meleeAttack(std::string const & target);
public:
	void action(std::string const & action_name, std::string const & target);

};


#endif //D02_HUMAN_HPP
