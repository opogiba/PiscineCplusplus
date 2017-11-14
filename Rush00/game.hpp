#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <string>
# include "Display.hpp"
# include "Entry.hpp"
# include "Enemy.hpp"
# include "Medical_help.hpp"
# include "Player.hpp"
# include "SpaceObject.hpp"
# include "Shield.hpp"
# include "Damage.hpp"
# define ENTRIES_NBR 80
# define ABS(x) ((x) < 0 ? -(x) : (x))

class               Game{
    Display         display;
    t_list          *entries;
    int             playerNbr;
    int             level;
    std::string     player_1;
    std::string     player_2;
    int             score;
    
    int             calculateObj(t_list*) const;
    int             checkEntries(int);
    void            checkPlayers(void);
    void            detectCollision(Entry* object);
    int             detectDead(void);
    void            addEntries(int);
    void            addBullet(Entry *bullet);
    void            showMenu(void);        
public:
                    Game(void);
                    Game(const Game&);
                    ~Game(void);
    void            mainLoop(void);
    int             init(void);
};

#endif