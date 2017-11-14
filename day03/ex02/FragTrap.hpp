

#ifndef D03_FRAGTRAP_HPP
#define D03_FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap{
private:
	void holyMolyShout(std::string const &target);
	void suckItShout(std::string const &target);
	void assShout(std::string const &target);
	void boomShout(std::string const &target);
	void grenadeShout(std::string const &target);
	void isdead();

public:
	FragTrap(std::string name);
	FragTrap();
	FragTrap(const FragTrap &a);
	~FragTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void vaulthunter_dot_exe(std::string const & target);
	void beRepaired(unsigned int amount);
	void takeDamage(unsigned int amount);
};



#endif //D03_FRAGTRAP_HPP
