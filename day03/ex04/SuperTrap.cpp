//
// Created by Oleksiy Pogiba on 11/3/17.
//

#include "SuperTrap.hpp"

SuperTrap::SuperTrap()  : ClapTrap(), FragTrap(), NinjaTrap() {

	std::cout << "Constructor - SUPERTRAP-TP : Let's get this party started! My name is Default" <<std::endl;
	_max_energy_points = 120;
	_energy_points = 120;
	_armor_damage_reduction = 5;
	_hit_points = 100;
	_max_hit_points = 100;
	_level = 1;
	_melee_attack_damage = 60;
	_ranged_attack_damage = 20;
}

SuperTrap::SuperTrap(std::string name)  : ClapTrap(name),FragTrap(name), NinjaTrap(name) {

	std::cout << "Constructor - SUPERTRAP-TP : Let's get this party started! My name is Default" <<std::endl;
	_max_energy_points = 120;
	_energy_points = 120;
	_armor_damage_reduction = 5;
	_hit_points = 100;
	_max_hit_points = 100;
	_level = 1;
	_melee_attack_damage = 60;
	_ranged_attack_damage = 20;
}

SuperTrap::SuperTrap(const SuperTrap &a)  : ClapTrap(a), FragTrap(), NinjaTrap() {
	std::cout << "Constructor - SUPERTRAP-TP : Recompiling my combat code! My name is "<< this->_Name <<std::endl;
}

SuperTrap::~SuperTrap() {
	std::cout << "Destructor - SUPERTRAP-TP : Is it dead? Can, can I open my eyes now?" <<std::endl;
}

void SuperTrap::rangedAttack(std::string const &target) {
	std::cout << "Attack - SUPERTRAP-TP : Solid! Get it? As in... frozen? - " <<_Name<<" attacks < "<< target <<" > at range, causing " <<_ranged_attack_damage << " points of damage !" << std::endl;;
}

void SuperTrap::meleeAttack(std::string const &target) {
	std::cout << "Attack -  SUPERTRAP-TP : That was me! I did that! " <<_Name<<" attacks < "<< target <<" > at melee, causing " <<_melee_attack_damage << " points of damage !" << std::endl;;
}

void SuperTrap::takeDamage(unsigned int amount)
{
	long long life;

	life = _hit_points - (long long)amount + _armor_damage_reduction;
	if(life > 0 && _hit_points > 0)
	{
		_hit_points = _hit_points - amount + _armor_damage_reduction;
		std::cout << "Damage -  SUPERTRAP-TP : " <<_Name<<" take damage "<<amount - _armor_damage_reduction <<" Life is " <<_hit_points << std::endl;
		return ;
	}
	_hit_points = 0;
	isdead();
}

void SuperTrap::beRepaired(unsigned int amount)
{
	unsigned int life;

	life = _hit_points + amount;
	if (_hit_points > 0 && life <= 100)
	{
		_hit_points += amount;
		std::cout << "Repair -  SUPERTRAP-TP : " <<_Name<<" repaired by "<< amount <<" Life is " <<_hit_points << std::endl;
		return;
	}
	if (life > 100)
		std::cout << "Status -  SUPERTRAP-TP : " <<_Name<<" can't have more then 100 HP" <<" Life is " <<_hit_points << std::endl;
	else
		isdead();

}

void SuperTrap::isdead() {
	std::cout << "Status - SUPERTRAP-TP : " <<_Name<<" dead" <<" Life is 0" << std::endl;

}
