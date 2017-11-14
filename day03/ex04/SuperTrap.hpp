//
// Created by Oleksiy Pogiba on 11/3/17.
//

#ifndef D03_SUPERTRAP_HPP
#define D03_SUPERTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap{
public:
	SuperTrap(std::string name);
	SuperTrap (const SuperTrap &a);
	SuperTrap();
	~SuperTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void beRepaired(unsigned int amount);
	void takeDamage(unsigned int amount);
	void isdead();


};


#endif //D03_SUPERTRAP_HPP
