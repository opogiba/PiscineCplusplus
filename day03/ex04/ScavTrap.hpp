
#ifndef D03_SCAVTRAP_HPP
#define D03_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
private:
	void isdead();
public:
	ScavTrap(std::string name);
	ScavTrap();
	ScavTrap(const ScavTrap &a);
	~ScavTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void challengeNewcomer();
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};


#endif //D03_SCAVTRAP_HPP
