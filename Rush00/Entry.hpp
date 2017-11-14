//
// Created by Oleksiy Pogiba on 11/4/17.
//

#ifndef RUSH00_ENTRY_HPP
# define RUSH00_ENTRY_HPP
# define BULLET ">"
# define ENEMY \
" /\\\n"\
"-|-\\\n"\
"=|*-=\n"\
"-|-/\n"\
" \\/"


# define MEDICAL \
" +\n"\
"+H+\n"\
" +"

# define PLAYER \
"/-\\\n"\
"---\n"\
"\\-/"

# define PLAYER2 \
"/-\\\n"\
"-=-\n"\
"\\-/"

# define DAMAGE \
" +\n"\
"+D+\n"\
" +"

# define SHIELD  \
" +\n"\
"+S+\n"\
" +"

# define OBJECT "*"
# define ENTRY "o"

# include "iostream"
# include "ame.hpp"
# include "ncurses.h"



class Entry {
protected:

	_event			_coord;
	_characters		_charters;
	int				_Max_HP;
	std::string		_name;
	int				_level;
	int				_CHP;
	int				_radius;
	int				_damage;
	int				_speed;
	Entry();
	Entry (const Entry &val);
	Entry(std::string name, int x, int y);
	Entry(int x, int y);

	virtual void move_up(int count);
	virtual void move_down(int count);
	virtual void move_right(int count);
	virtual void move_left(int count);
	
public:
	
	Entry& operator=(const Entry &val);
	Entry& operator+=(int val);
	Entry& operator-=(int val);
	const _event &get_coord() const;


	virtual ~Entry();
	virtual void		move(int);
	virtual void		takeDamage(int amount);
	virtual void		level_up();
	int					get_Max_HP() const;
	const std::string	&get_name() const;
	int 				get_level() const;
	int					get_radius(void) const;
	int 				get_CHP() const;
	int					get_speed() const;
	virtual int			get_damage() const;
	const _characters 	&get_charters() const;
	void				set_coord(const _event &_coord);
	virtual int			get_index(void) const;

};


#endif //RUSH00_ENTRY_HPP
