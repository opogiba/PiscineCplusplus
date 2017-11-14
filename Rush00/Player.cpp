
#include "Player.hpp"

int Player::_Index = -1;

Player::Player() : Entry() {
	_Player_index = ++_Index;
	_name = "Player " + std::to_string(_Index + 1);
	_Max_HP = 3;
	_Damage_def = 5;
	_CHP = _Max_HP;
	_damage = _Damage_def;
	_charters.color = 2;
	_charters.shape = PLAYER;
	_speed = 1;
	_shield = 0;
	_score = 0;
}

Player::Player(std::string name, int x, int y) : Entry(name, x, y) {
	_Player_index = ++_Index;
	_name = name;
	_Max_HP = 3;
	_Damage_def = 5;
	_CHP = _Max_HP;
	_damage = _Damage_def;
	_charters.color = 2;
	_charters.shape = PLAYER;
	_speed = 1;
	_shield = 0;
	_score = 0;
}
Player::Player(int x, int y) : Entry( x, y) {
	_Player_index = ++_Index;
	_name = "Player " + std::to_string(_Index + 1);;
	_Max_HP = 3;
	_Damage_def = 5;
	_CHP = _Max_HP;
	_damage = _Damage_def;
	_charters.color = 2;
	if (_Player_index == 0)
		_charters.shape = PLAYER;
	else
		_charters.shape = PLAYER2;
	_speed = 1;
	_shield = 0;
	_score = 0;
	_radius = 1;	
}

Player::Player (const Player &val) : Entry(val)
{
	*this = val;
	this->_Player_index = ++_Index;
}

Player& Player::operator=(const Player &val) {
	Entry::operator=(val);
	if (this == &val)
	{
		return *this;
	}
	this->_Damage_def = val._Damage_def;
	this->_score = val._score;
	this->_shield = val._shield;
	return (*this);
}

void Player::level_up() {
	_level++;
	_CHP = _Max_HP;
	_Damage_def = _damage++;
	_damage = _Damage_def;
	_shield = 0;
}

void Player::move(int symbol){
	if(this->get_index() == 1) {
		switch (symbol) {
			case KEY_UP:
				this->_coord.Y--;
				break;
			case KEY_DOWN:
				this->_coord.Y++;
				break;
			case KEY_RIGHT:
				this->_coord.X++;
				break;
			case KEY_LEFT:
				this->_coord.X--;
				break;
			default:
				break;
		}
	}
	else if (this->get_index() == 0) {
		switch (symbol) {
			case 'w':
				this->_coord.Y--;
				break;
			case 's':
				this->_coord.Y++;
				break;
			case 'd':
				this->_coord.X++;
				break;
			case 'a':
				this->_coord.X--;
				break;
			default:
				break;
		}

	}

}

void Player::upScore() {
	this->_score += 10;
}

void Player::take_medical_help() {
	if(_CHP + 1 > _Max_HP)
		_CHP = _Max_HP;
	else
		_CHP += 1;
}

void Player::take_additional_damage() {
	this->_damage = this->_damage + this->_level;
};

void Player::lose_additional_damage()
{
	this->_damage = this->_Damage_def;
}

void Player::take_Shield()
{
	_shield = 1;
}

void Player::takeDamage(int amount) {
	int life;

	life = this->_CHP - amount;
	if (_shield == 0)
	{
		if (life > 0)
			this->_CHP = life;
		else
			this->_CHP = 0;
	}
	else
		_shield = 0;
}


Entry * Player::attack()
{
	Bullet *bul = new Bullet(this->_coord.X + this->_radius + 1, this->_coord.Y, this->_damage, TRUE);
	return (bul);
}


Player::~Player() {

}

int Player::get_score() const {
	return _score;
}

int	Player::get_index(void) const{
	return _Player_index;
}