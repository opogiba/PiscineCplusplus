
#ifndef RUSH00_PLAYER_HPP
#define RUSH00_PLAYER_HPP



#include "Entry.hpp"
#include "Bullet.hpp"

class Player : public Entry {
private:
	int _Player_index;
	int _Damage_def;
	static int _Index;
	int _shield;
	int _score;

	Player();
public:
	Player(std::string name, int x, int y);
	Player(int x, int y);
	Player (const Player &val);
	~Player();
	Player& operator=(const Player &val);

	void move(int);
	void take_medical_help();
	void take_Shield();
	void takeDamage(int amount);
	void take_additional_damage();
	void lose_additional_damage();
	void upScore();
	void level_up();


	Entry * attack();

	int get_score() const;
	int get_index() const;
};


#endif //RUSH00_PLAYER_HPP
