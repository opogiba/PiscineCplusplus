#ifndef D03_CLAPTRAP_HPP
#define D03_CLAPTRAP_HPP

#include <iostream>



class ClapTrap {
protected:
	int _max_hit_points;
	int _max_energy_points;
	int _melee_attack_damage;
	int _ranged_attack_damage;
	int _armor_damage_reduction;


	int _hit_points;
	int _energy_points;
	int _level;
	virtual void isdead();
	std::string _Name;
public:
	virtual void beRepaired(unsigned int amount);
	virtual void takeDamage(unsigned int amount);
	ClapTrap(std::string name);
	ClapTrap (const ClapTrap &a);
	ClapTrap();
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &val);
	virtual void rangedAttack(std::string const & target);
	virtual void meleeAttack(std::string const & target);

};


//ClapTrap a = new ScavTrap();
//ScavTrap s = new ScavTrap();
//
////virtual rangedAttack
//s.rangedAttack(); //-> ScavTrap::rangedAttack();
//a.rangedAttack(); //-> ScavTrap::rangedAttack();
//
////not virtual rangedAttack
//s.rangedAttack(); //-> ScavTrap::rangedAttack();
//a.rangedAttack(); //-> ClapTrap::rangedAttack();

#endif //D03_CLAPTRAP_HPP
