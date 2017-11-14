//
// Created by Oleksiy Pogiba on 11/4/17.
//

#ifndef RUSH00_GAME_HPP
# define RUSH00_GAME_HPP
# include <string>

typedef struct		_event{

	int				X;
	int				Y;

}					_event;

typedef struct		_characters {
	std::string		shape;
	int				color;
}					_characters;

#endif //RUSH00_GAME_HPP
