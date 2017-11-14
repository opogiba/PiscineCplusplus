#include "Game.hpp"
void    *bullet;
/*
**  Constructors
*/
Game::Game(void){
    this->entries = nullptr;
    this->playerNbr = 1;
    this->level = 1;
    this->score = 0;
}

Game::~Game(void){
}

Game::Game(const Game& obj){
    (void)obj;
}




/*
**  Other functions
*/
int             Game::calculateObj(t_list *ptr) const{
    int         counter = 0;
    _characters tmp;

    while (ptr){
        tmp = ptr->obj->get_charters();
        if (tmp.shape != BULLET)
            counter++;
        ptr = ptr->next;
    }
    return (counter);
}

void            Game::checkPlayers(void){
    t_list      *ptr;

    if (this->entries == nullptr){
        this->entries = new t_list;
        ptr = this->entries;
        ptr->obj = new Player(2, this->display.getHeight() / 3);
        ptr->next = nullptr;
        if (this->playerNbr > 1){
            ptr->next = new t_list;
            ptr = ptr->next;
            ptr->obj = new Player(2, 2 * this->display.getHeight() / 3);;
            ptr->next = nullptr;
        }
    }
}

void            Game::detectCollision(Entry* object){
    t_list      *ptr = this->entries;
    _characters charact;
    int         width = this->display.getWidth();
    int         height = this->display.getHeight();
    _event      coord;
    _event      e_coord;
    int         radius;
    int         e_radius;
    int         is_player = 0;

    charact = object->get_charters();
    is_player = (charact.shape == PLAYER || charact.shape == PLAYER2) ? 1 : 0;
    coord = object->get_coord();
    radius = object->get_radius();
    if ((coord.X < 0 || coord.X > width) && !is_player)
        object->takeDamage(1000);
    else if (is_player){
        if (coord.X < 4)
            coord.X = 4;
        if (coord.Y < 1)
            coord.Y = height - 2;
        else if (coord.Y > height - 2)
            coord.Y = 2;
        else if (coord.X >= width - 4)
            coord.X = width - 4;
        object->set_coord(coord);
    }
    while (ptr){
        if (ptr->obj == object){
            ptr = ptr->next;
            continue;
        }
        e_coord = ptr->obj->get_coord();
        e_radius = ptr->obj->get_radius();
        if ((ABS(coord.X - e_coord.X) < radius + e_radius + 1) &&
            (ABS(coord.Y - e_coord.Y) < radius + e_radius + 1)){
            if (charact.shape == BULLET)
                this->score++;
            charact = ptr->obj->get_charters();
            if (charact.shape == BULLET)
                this->score++;
            object->takeDamage(ptr->obj->get_damage());
            ptr->obj->takeDamage(object->get_damage());
            if (this->score && this->score % 30 == 0)
                this->level++;
        }
        ptr = ptr->next;
    }
}

int             Game::detectDead(void){
    t_list      *ptr = this->entries;
    t_list      *priv = this->entries;
    _characters charact;
    int         players = 0;
    
    while (ptr){
        if (ptr->obj->get_CHP() <= 0){
            if (priv == ptr){
                this->entries = ptr->next;
                ptr = ptr->next;
                delete priv->obj;
                delete priv;
                priv = ptr;
            } else {
                priv->next = ptr->next;
                delete ptr->obj;
                delete ptr;
                ptr = priv->next;
            }
        } else {
            charact = ptr->obj->get_charters();
            players += charact.shape == PLAYER ? 1 : 0;          
            priv = ptr;
            ptr = ptr->next;
        }
    }
    return (0);
}

void            Game::addEntries(int nbr){
    t_list      *ptr = this->entries;
    int         random;

    while (ptr->next)
    ptr = ptr->next;
    srand(clock());
    while (nbr > 0){
        ptr->next = new t_list;
        ptr = ptr->next;
        random = rand() % 12;
        if (random < 4)
            ptr->obj = new Enemy(this->display.getWidth() - 5, rand() % this->display.getHeight());
        else if (random < 9)
            ptr->obj = new SpaceObject(this->display.getWidth() - 5, rand() % this->display.getHeight());
        else if (random == 9)
            ptr->obj = new Medical_help(this->display.getWidth() - 5, rand() % this->display.getHeight());
        else if (random == 10)
            ptr->obj = new Shield(this->display.getWidth() - 5, rand() % this->display.getHeight());
        else if (random == 11)
            ptr->obj = new Damage(this->display.getWidth() - 5, rand() % this->display.getHeight());
        ptr->next = nullptr;
        nbr--;
    }
}

void            Game::addBullet(Entry *bullet){
    t_list      *ptr = this->entries;

    while (ptr->next)
        ptr = ptr->next;
    ptr->next = new t_list;
    ptr = ptr->next;
    ptr->next = nullptr;
    ptr->obj = bullet;
}

int             Game::checkEntries(int key){
    t_list      *ptr;
    int         entriesNbr = 0;
    _characters ch;
    int         players = 0;

    clear();
    this->checkPlayers();
    ptr = this->entries;
    while (ptr){
        ch = ptr->obj->get_charters();
        if (ch.shape == PLAYER || ch.shape == PLAYER2){
            players++;
            if (key == ' ' && ch.shape == PLAYER)
                this->addBullet(((Player*)ptr->obj)->attack());
            else if (key == '0' && ch.shape == PLAYER2)
                this->addBullet(((Player*)ptr->obj)->attack());
        }
        ptr->obj->move(key);
        this->detectCollision(ptr->obj);
        ptr = ptr->next;
    }
    this->detectDead();
    entriesNbr = this->calculateObj(this->entries);
    
    if (entriesNbr < this->level * ENTRIES_NBR)
        this->addEntries(1);
    return (players);
}


int             Game::init(void){
    return this->display.init();
}

void            Game::showMenu(void){
    std::string players;
    int         delim;

    players = this->display.showMenu();
    delim = players.find("|");
    this->player_1 = players.substr(0, delim++);
    this->player_2 = players.substr(delim, players.length());
    if (this->player_2.length() > 1)
        this->playerNbr = 2;
}

void            Game::mainLoop(void){
    int         key;
    int         status = 0;

    this->showMenu();
    while (!status){
        key = this->display.getKey();
        if (this->checkEntries(key) == 0)
            status = -1;
        if (key == 'q')
            break;
        this->display.render(this->entries, this->score, this->level, this->player_1, this->player_2);
        usleep(50000 / this->level);        
    }
    //showLastScreen(status);
}
/*
**  Non members
*/
