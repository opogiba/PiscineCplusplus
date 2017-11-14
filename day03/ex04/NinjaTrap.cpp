#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name){
	std::cout << "Constructor - NINJA-TP : I can't feel my fingers! Gah! I don't have any fingers! My name is "<<name <<std::endl;
	_max_energy_points = 120;
	_energy_points = 120;
	_armor_damage_reduction = 0;
	_hit_points = 60;
	_max_hit_points = 60;
	_level = 1;
	_melee_attack_damage = 60;
	_ranged_attack_damage = 5;


}

NinjaTrap::NinjaTrap() : ClapTrap(){
	std::cout << "Constructor - NINJA-TP : You call yourself a badass? My name is Default" <<std::endl;
	_max_energy_points = 120;
	_energy_points = 120;
	_armor_damage_reduction = 0;
	_hit_points = 60;
	_max_hit_points = 60;
	_level = 1;
	_melee_attack_damage = 60;
	_ranged_attack_damage = 5;

}

NinjaTrap::NinjaTrap(const NinjaTrap &a) : ClapTrap(a) {

	std::cout << "Constructor - NINJA-TP :  I have gaskets tougher than you!My name is "<<  this->_Name <<std::endl;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "Destructor - NINJA-TP : Why do I even feel pain?!" <<std::endl;
}

void NinjaTrap::isdead() {
	std::cout << "Status - NINJA-TP :" <<_Name<<" dead" <<" Life is 0" << std::endl;

}

void NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "Attack - NINJA-TP : Solid! Get it? As in... frozen? - " <<_Name<<" attacks < "<< target <<" > at range, causing " <<_ranged_attack_damage << " points of damage !" << std::endl;;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "Attack - NINJA-TP : I am a robot popsicle! - "  <<_Name<<" attacks < "<< target <<" > at melee, causing " <<_melee_attack_damage << " points of damage !" << std::endl;;
}





void NinjaTrap::ninjaAttack(FragTrap &a) {
	std::cout << "Attack - NINJA-TP : NINJA-TP " <<_Name << " Attack FR4G-TP" <<std::endl;
	a.takeDamage(35);

}
void NinjaTrap::ninjaAttack(ScavTrap &a) {
	std::cout << "Attack - NINJA-TP : NINJA-TP " <<_Name << " Attack SCAV-TP" <<std::endl;
	a.takeDamage(25);

}
void NinjaTrap::ninjaAttack(NinjaTrap &a) {
	std::cout << "Attack - NINJA-TP : NINJA-TP " <<_Name << " Hill NINJA-TP"  <<std::endl;
	a.beRepaired(20);
}

void NinjaTrap::takeDamage(unsigned int amount)
{
	long long life;

	life = _hit_points - (long long)amount + _armor_damage_reduction;
	if(life > 0 && _hit_points > 0)
	{
		_hit_points = _hit_points - amount + _armor_damage_reduction;
		std::cout << "Damage - NINJA-TP : " <<_Name<<" take damage "<<amount - _armor_damage_reduction <<" Life is " <<_hit_points << std::endl;
		return ;
	}
	_hit_points = 0;
	isdead();
}

void NinjaTrap::beRepaired(unsigned int amount)
{
	unsigned int life;

	life = _hit_points + amount;
	if (_hit_points > 0 && life <= 60)
	{
		_hit_points += amount;
		std::cout << "Repair - NINJA-TP : " <<_Name<<" repaired by "<< amount <<" Life is " <<_hit_points << std::endl;
		return;
	}
	if (life > 60)
		std::cout << "Status - NINJA-TP : " <<_Name<<" can't have more then 60 HP" <<" Life is " <<_hit_points << std::endl;
	else
		isdead();

}