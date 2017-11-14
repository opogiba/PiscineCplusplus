#include "Display.hpp"

/*
**  Constructors
*/
Display::Display(void){
}

Display::~Display(void){
    endwin();
}

Display::Display(const Display& obj){
    (void)obj;
}

/*
**  Operators
*/
Display& Display::operator=(const Display& old){
    (void)old;    
    return *this;
}

/*
**  Getters
*/

std::ostream&   Display::toStream(std::ostream& stream) const
{
    stream << std::endl;
	return stream;
}

int             Display::getWidth(void) const{
    return this->width;
}

int             Display::getHeight(void) const{
    return this->height;
}

/*
**  Private functions
*/ 

/*
**  Other functions
*/
int             Display::init(void){
    this->win = initscr();      
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(this->win, TRUE);
    if (!has_colors())
        return (-1);
    start_color();
    init_pair(1, COLOR_BLUE,  COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_BACKGROUND);
    init_pair(3, COLOR_RED,   COLOR_BACKGROUND);
    init_pair(4, COLOR_GREEN, COLOR_BACKGROUND); 
    init_pair(5, COLOR_YELLOW, COLOR_BACKGROUND);
    init_pair(6, COLOR_MAGENTA, COLOR_BACKGROUND);
    init_pair(7, COLOR_CYAN, COLOR_BACKGROUND);
    init_pair(8, COLOR_WHITE, COLOR_BACKGROUND);
    init_pair(9, COLOR_BLUE, COLOR_BACKGROUND);
    
 //   wbkgd(this->win, COLOR_PAIR(1));
    this->width = getmaxx(this->win);
    this->height = getmaxy(this->win);
    return (0);
}
int             Display::getKey(void){
    return wgetch(this->win);
}

void            Display::showLogo(int middle, int& y){
    mvwprintw(this->win, y++, middle, "============================================");      
    mvwprintw(this->win, y++, middle, "=             AMAZING STAR BATTLES         =");      
    mvwprintw(this->win, y++, middle, "============================================");  
    mvwprintw(this->win, y++, middle, "|                          *   .--.        |");
    mvwprintw(this->win, y++, middle, "|                            / /  `        |");
    mvwprintw(this->win, y++, middle, "|           +               | |            |");
    mvwprintw(this->win, y++, middle, "|                  '         \\ \\__,        |");
    mvwprintw(this->win, y++, middle, "|              *          +   '--'  *      |");
    mvwprintw(this->win, y++, middle, "|                  +   /\\                  |");
    mvwprintw(this->win, y++, middle, "|     +              .'  '.   *            |");
    mvwprintw(this->win, y++, middle, "|            *      /======\\       +       |");
    mvwprintw(this->win, y++, middle, "|                  ;:.  _   ;              |");
    mvwprintw(this->win, y++, middle, "|                  |:. (_)  |              |");
    mvwprintw(this->win, y++, middle, "|                  |:.  _   |              |");
    mvwprintw(this->win, y++, middle, "|        +         |:. (_)  |          *   |");
    mvwprintw(this->win, y++, middle, "|                  ;:.      ;              |");
    mvwprintw(this->win, y++, middle, "|                .' \\:.    / `.            |");
    mvwprintw(this->win, y++, middle, "|               / .-'':._.'`-. \\           |");
    mvwprintw(this->win, y++, middle, "|               |/    /||\\    \\|           |");
    mvwprintw(this->win, y++, middle, "|            _..--\"\"\"\"\"\"\"\"\"\"--.._          |");
    mvwprintw(this->win, y++, middle, "|       _.-'``                    ``'-._   |");
    mvwprintw(this->win, y++, middle, "|     -'                                '- |");
    mvwprintw(this->win, y++, middle, "============================================");  
}

std::string     Display::showMenu(void){
    int         middle;
    int         key;
    int         y;
    int         nbr = 1;
    char        names[2][200] = {};
    int         i = 0;
    std::string ret;
    
    clear();
    middle = this->width / 2 - strlen("============================================") / 2; 
    attron(COLOR_PAIR(1));
    while (1){
        y = 5;
        this->showLogo(middle, y);      
        mvwprintw(this->win, y++, middle, "=       PLEASE, SELECT PLAYERS NUMBER      =");  
        mvwprintw(this->win, y++, middle, "============================================");  
        mvwprintw(this->win, y++, middle, "=                    %d                     =", nbr);
        key = wgetch(this->win);
        if (key == 10)
            break ;
        nbr = nbr == 1 ? 2 : 1;
    }
    echo();
    while (nbr - i > 0){
        clear();
        y = 5;
        this->showLogo(middle, y);      
        mvwprintw(this->win, y++, middle, "=        PLEASE, ENTER %d PLAYER NAME       =", i + 1);  
        mvwprintw(this->win, y++, middle, "============================================");  
        mvwprintw(this->win, y++, middle, "=                                          =");
        move(y - 1, middle + 10);
        scanw((char*)"%s", names[i]);
        if (strlen(names[i]) != 0)
            i++;       
    }
    noecho();
    attron(A_BOLD);
    attroff(COLOR_PAIR(1));
    box(this->win, 0, 0);
    attroff(A_BOLD);
    ret = names[0];
    ret += "|";
    ret += names[1];
    refresh();
    wbkgd(this->win, COLOR_PAIR(2));
    nodelay(this->win, true);
    return (ret);
}
/*
void            display::score(){

}
*/

void            Display::drawEntry(int x, int y, int color, std::string shape)
{
    int         lines = 1;
    int         i = 0;
    int         j;
    char        ptr[100];
    char        *tmp;

    strcpy(ptr, shape.c_str());
    tmp = ptr;
    while (*tmp){
        if (*tmp == '\n')
            lines++;
        tmp++;
    }
    tmp = ptr;
    j = -1;    
    attron(COLOR_PAIR(color));
    while (i < lines){
        tmp = tmp + j + 1;
        j = 0;
        while (tmp[j] && tmp[j] != '\n')
        j++;
        tmp[j] = 0;
        mvwprintw(this->win, y + i - lines / 2, x - lines / 2, tmp);
        i++;
    }
    attroff(COLOR_PAIR(color));
}
void            Display::render(t_list *list, int score, int level, std::string player_1, std::string player_2){
    static int  counter;
    _event      tmp = {0, 0};
    _characters character;

    score++;
    level++;
    player_1 = player_2;
    if ((counter % 100) == 0){
        this->width = getmaxx(this->win);
        this->height = getmaxy(this->win);
    }
    clear();
    while (list){
        //list->obj->move
        tmp = list->obj->get_coord();
        character = list->obj->get_charters();
        this->drawEntry(tmp.X, tmp.Y, character.color, character.shape);   
        list = list->next;           
    }
    attron(A_BOLD);
    box(this->win, 0, 0);
    attroff(A_BOLD);
    refresh();
}

/*
**  Non members
*/
std::ostream& operator<<(std::ostream& stream, const Display& object)
{
	return (object.toStream(stream));
}