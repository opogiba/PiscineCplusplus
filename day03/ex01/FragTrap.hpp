

#ifndef D03_FRAGTRAP_HPP
#define D03_FRAGTRAP_HPP
#include <iostream>


class FragTrap {
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
	void holyMolyShout(std::string const &target);
	void suckItShout(std::string const &target);
	void assShout(std::string const &target);
	void boomShout(std::string const &target);
	void grenadeShout(std::string const &target);

public:

	FragTrap(std::string name);
	FragTrap();
	FragTrap(const FragTrap &a);
	~FragTrap();
	FragTrap& operator=(const FragTrap &val);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);
	void beRepaired(unsigned int amount);

};



#endif //D03_FRAGTRAP_HPP
