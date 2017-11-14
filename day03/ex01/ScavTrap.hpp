
#ifndef D03_SCAVTRAP_HPP
#define D03_SCAVTRAP_HPP
#include <iostream>

class ScavTrap {
private:
	static int _max_hit_points;
	static int _max_energy_points;
	static int _melee_attack_damage;
	static int _ranged_attack_damage;
	static int _armor_damage_reduction;
	int _hit_points;
	int _energy_points;
	int _level;
	std::string _Name;
	void isdead();


public:

	ScavTrap(std::string name);
	ScavTrap();
	ScavTrap(const ScavTrap &a);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap &val);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);
	void challengeNewcomer();

};


#endif //D03_SCAVTRAP_HPP
