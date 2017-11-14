#ifndef DISPLAY_HPP
# define DISPLAY_HPP
# include <iostream>
# include <string>
# include <ncurses.h>
# include <unistd.h>
# include "Entry.hpp"
# define COLOR_BACKGROUND COLOR_WHITE

typedef struct      s_list{
    Entry           *obj;
    struct s_list   *next;
}                   t_list;

class               Display{
    int             width;
    int             height;
    WINDOW          *win;
    Entry           *tmp;
    void            showLogo(int middle, int&);  
    void            drawEntry(int x, int y, int color, std::string shape);      
public:
                    Display(void);
                    Display(const Display&);
                    ~Display(void);
    int             getKey(void);
    int             getWidth(void) const;
    int             getHeight(void) const;
    void            setSpeed(int);
    std::ostream&   toStream(std::ostream&) const;
    Display&        operator=(const Display&);
    int             init(void);
    void            render(t_list*, int, int, std::string, std::string);
    std::string     showMenu(void);        

    
};

std::ostream&       operator<<(std::ostream&, const Display&);
#endif