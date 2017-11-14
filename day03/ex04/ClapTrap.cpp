//
// Created by Oleksiy Pogiba on 11/2/17.
//


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	_Name = name;
	_max_hit_points = 0;
	_melee_attack_damage = 0;
	_ranged_attack_damage = 0;
	_max_energy_points = 0;
	_armor_damage_reduction = 0;
	_hit_points = 0;
	_energy_points = 0;
	_level = 0;
	srand(clock());
}

ClapTrap::ClapTrap() {
	_Name = "Default";
	_max_hit_points = 0;
	_melee_attack_damage = 0;
	_ranged_attack_damage = 0;
	_max_energy_points = 0;
	_armor_damage_reduction = 0;
	_hit_points = 0;
	_energy_points = 0;
	_level = 0;
	srand(clock());
}



ClapTrap ::~ClapTrap() {

}

ClapTrap ::ClapTrap(const ClapTrap &a) {
	*this = a;
}

/////////////////////////DAMAGE///////////////////////////////

void ClapTrap::takeDamage(unsigned int amount)
{
//	long long life;
//
//	life = _hit_points - (long long)amount + _armor_damage_reduction;
//	if(life > 0 && _hit_points > 0)
//	{
//		_hit_points = _hit_points - amount + _armor_damage_reduction;
//		std::cout << "Damage : FR4G-TP " <<_Name<<" take damage "<<amount - _armor_damage_reduction <<" Life is " <<_hit_points << std::endl;
//		return ;
//	}
//	_hit_points = 0;
//	isdead();
	std::cout << "CLAP-TP cannot take damage - "<< amount << std::endl;;
}

void ClapTrap::beRepaired(unsigned int amount)
{
//	unsigned int life;
//
//	life = _hit_points + amount;
//	if (_hit_points > 0 && life <= 100)
//	{
//		_hit_points += amount;
//		std::cout << "Repair : FR4G-TP " <<_Name<<" repaired by "<< amount <<" Life is " <<_hit_points << std::endl;
//		return;
//	}
//	if (life > 100)
//		std::cout << "Status : FR4G-TP " <<_Name<<" can't have more then 100 HP" <<" Life is " <<_hit_points << std::endl;
//	else
//		isdead();
	std::cout << "Status - CLAP-TP : CLAP-TP cannot be repair - "<< amount << std::endl;;

}

void ClapTrap::isdead() {
	std::cout << "Status - CLAP-TP : CLAP-TP cannot be dead " << std::endl;
}
void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "Status - CLAP-TP : CLAP-TP cannot attack "<<target << std::endl;
}
void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "Status - CLAP-TP : CLAP-TP cannot attack " << target << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &val) {
	if (this == &val)
		return *this;
	_Name = val._Name;
	_hit_points = val._hit_points;
	_energy_points = val._energy_points;
	_level = val._level;
	_max_energy_points = val._max_energy_points;
	_armor_damage_reduction = val._armor_damage_reduction;
	return (*this);
}