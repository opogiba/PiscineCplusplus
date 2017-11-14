#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "Constructor - SCAV-TP : I am a tornado of death and bullets! My name is "<<name <<std::endl;

	_max_energy_points = 50;
	_energy_points = 50;
	_armor_damage_reduction = 3;
	_hit_points = 100;
	_max_hit_points = 100;
	_level = 1;
	_melee_attack_damage = 20;
	_ranged_attack_damage = 15;


}

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "Constructor - SCAV-TP : Ha ha ha! Fall before your robot overlord! My name is Default" <<std::endl;
	_max_energy_points = 50;
	_energy_points = 50;
	_armor_damage_reduction = 3;
	_hit_points = 100;
	_max_hit_points = 100;
	_level = 1;
	_melee_attack_damage = 20;
	_ranged_attack_damage = 15;
}

ScavTrap::ScavTrap(const ScavTrap &a) : ClapTrap(a) {

	std::cout << "Constructor - SCAV-TP : Ha! Keep 'em coming! My name is "<<  this->_Name <<std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor - SCAV-TP : Wow, did I really do that?" <<std::endl;
}

void ScavTrap::isdead() {
	std::cout << "Status - SCAV-TP: " <<_Name<<" dead" <<" Life is 0" << std::endl;

}
void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "Attack - SCAV-TP : Take a chill pill! - "<< "SCAV-TP " <<_Name<<" attacks < "<< target <<" > at range, causing " <<_ranged_attack_damage << " points of damage !" << std::endl;;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "Attack - SCAV-TP : Freeze! I don't know why I said that. - " << "SCAV-TP " <<_Name<<" attacks < "<< target <<" > at melee, causing " <<_melee_attack_damage << " points of damage !" << std::endl;;
}

void ScavTrap::challengeNewcomer() {
	std::string command1 = "I'm pulling tricks outta my hat!";
	std::string command2 = "Push this button, flip this dongle, voila! Help me!";
	std::string command3 = "Look out everybody, things are about to get awesome!";
	std::string command4 = "F to the R to the 4 to the G to the WHAAT!";
	std::string command5 = "Oh god I can't stop!";
	std::string commands[5] = {
			command1,
			command2,
			command3,
			command4,
			command5
	};
	int random;

	random = rand() % 5;
	std::cout << "Command - SCAV-TP : ";
	std::cout << commands[random] << std::endl;;
}

/////////////////////////DAMAGE///////////////////////////////

void ScavTrap::takeDamage(unsigned int amount)
{
	long long life;

	life = _hit_points - (long long)amount + _armor_damage_reduction;
	if(life > 0 && _hit_points > 0)
	{
		_hit_points = _hit_points - amount + _armor_damage_reduction;
		std::cout << "Damage - SCAV-TP : " <<_Name<<" take damage "<<amount - _armor_damage_reduction <<" Life is " <<_hit_points << std::endl;
		return ;
	}
	_hit_points = 0;
	isdead();
}

void ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int life;

	life = _hit_points + amount;
	if (_hit_points > 0 && life <= 100)
	{
		_hit_points += amount;
		std::cout << "Repair - SCAV-TP :  " <<_Name<<" repaired by "<< amount <<" Life is " <<_hit_points << std::endl;
		return;
	}
	if (life > 100)
		std::cout << "Status - SCAV-TP: " <<_Name<<" can't have more then 100 HP" <<" Life is " <<_hit_points << std::endl;
	else
		isdead();

}
