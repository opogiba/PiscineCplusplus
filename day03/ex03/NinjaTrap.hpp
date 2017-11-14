
#include "ClapTrap.hpp"

#ifndef D03_NINJATRAP_HPP
#define D03_NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class NinjaTrap : public ClapTrap {
private:
	void isdead();
public:
	NinjaTrap(std::string name);
	NinjaTrap();
	NinjaTrap(const NinjaTrap &a);
	~NinjaTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void ninjaAttack(ClapTrap &a);
	void ninjaAttack(FragTrap &a);
	void ninjaAttack(ScavTrap &a);
	void ninjaAttack(NinjaTrap &a);
	void beRepaired(unsigned int amount);
	void takeDamage(unsigned int amount);
};


#endif //D03_NINJATRAP_HPP
