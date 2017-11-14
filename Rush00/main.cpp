#include "Display.hpp"
#include "Game.hpp"
#include <ncurses.h>
#include <unistd.h>

int             main(void){
    Game        game;
       
    if (!game.init()){
        game.mainLoop();
    }
    return 0;
}