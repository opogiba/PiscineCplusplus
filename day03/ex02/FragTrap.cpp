#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name)  {
	std::cout << "Constructor - FR4G-TP : Hehehehe, mwaa ha ha ha, MWAA HA HA HA! My name is "<<name <<std::endl;
	_max_energy_points = 100;
	_energy_points = 100;
	_armor_damage_reduction = 5;
	_hit_points = 100;
	_max_hit_points = 100;
	_level = 1;
	_melee_attack_damage = 30;
	_ranged_attack_damage = 20;
}

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "Constructor - FR4G-TP : Let's get this party started! My name is Default" <<std::endl;
	_max_energy_points = 100;
	_energy_points = 100;
	_armor_damage_reduction = 5;
	_hit_points = 100;
	_max_hit_points = 100;
	_level = 1;
	_melee_attack_damage = 30;
	_ranged_attack_damage = 20;
}

FragTrap::FragTrap(const FragTrap &a)  : ClapTrap(a) {
	std::cout << "Constructor - FR4G-TP : Recompiling my combat code! My name is "<< this->_Name <<std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor - FR4G-TP : Is it dead? Can, can I open my eyes now?" <<std::endl;
}

void FragTrap::isdead() {
	std::cout << "Status - FR4G-TP : " <<_Name<<" dead" <<" Life is 0" << std::endl;

}




/////////////////////////ATTACKs/////////////////////////////

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "Attack - FR4G-TP : I have gaskets tougher than you! " <<_Name<<" attacks < "<< target <<" > at range, causing " <<_ranged_attack_damage << " points of damage !" << std::endl;;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "Attack - FR4G-TP : That was me! I did that! " <<_Name<<" attacks < "<< target <<" > at melee, causing " <<_melee_attack_damage << " points of damage !" << std::endl;;
}

void FragTrap::holyMolyShout(std::string const &target) {
	std::cout << "Attack - FR4G-TP : Holy Moly! " <<_Name<<" attacks < "<< target <<" > at Holy Moly, causing 5 points of damage !" << std::endl;;
}

void FragTrap::suckItShout(std::string const &target) {
	std::cout << "Attack - FR4G-TP : Ha ha ha! Suck it! " <<_Name<<" attacks < "<< target <<" > at suck, causing 10 points of damage !" << std::endl;;
}

void FragTrap::assShout(std::string const &target) {
	std::cout << "Attack - FR4G-TP : Don't cryo! " <<_Name<<" attacks < "<< target <<" > at ass, causing 15 points of damage !" << std::endl;;
}

void FragTrap::boomShout(std::string const &target) {
	std::cout << "Attack - FR4G-TP : Bad guy go boom! " <<_Name<<" attacks < "<< target <<" > boom, causing 10 points of damage !" << std::endl;;
}

void FragTrap::grenadeShout(std::string const &target) {
	std::cout << "Attack - FR4G-TP : Grenaaaade! " <<_Name<<" attacks < "<< target <<" > Grenaaaade!, causing 15 points of damage !" << std::endl;;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int random;

	if (_energy_points >= 25)
	{
		_energy_points -= 25;
		random = rand() % 5;
		void (FragTrap::*ptr[5])(std::string const &) = {
				&FragTrap::holyMolyShout,
				&FragTrap::suckItShout,
				&FragTrap::boomShout,
				&FragTrap::grenadeShout,
				&FragTrap::assShout
		};
		(this->*ptr[random])(target);

	}
	else {
		std::cout << "Status - FR4G-TP : " <<_Name<<" hasnt enough energy" << std::endl;
	}
}

/////////////////////////DAMAGE///////////////////////////////

void FragTrap::takeDamage(unsigned int amount)
{
	long long life;

	life = _hit_points - (long long)amount + _armor_damage_reduction;
	if(life > 0 && _hit_points > 0)
	{
		_hit_points = _hit_points - amount + _armor_damage_reduction;
		std::cout << "Damage - FR4G-TP : " <<_Name<<" take damage "<<amount - _armor_damage_reduction <<" Life is " <<_hit_points << std::endl;
		return ;
	}
	_hit_points = 0;
	isdead();
}

void FragTrap::beRepaired(unsigned int amount)
{
	unsigned int life;

	life = _hit_points + amount;
	if (_hit_points > 0 && life <= 100)
	{
		_hit_points += amount;
		std::cout << "Repair - FR4G-TP : " <<_Name<<" repaired by "<< amount <<" Life is " <<_hit_points << std::endl;
		return;
	}
	if (life > 100)
		std::cout << "Status - FR4G-TP : " <<_Name<<" can't have more then 100 HP" <<" Life is " <<_hit_points << std::endl;
	else
		isdead();

}

///////////////////////////////END////////////////////////////



