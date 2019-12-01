#include <ncurses.h>
#include <stdlib.h>

#include "menu.h"
#include "game.h"
#include "editeur.h"



int main(int argc, char* argv){

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    if(has_colors == FALSE){
        endwin();
        return -1;
    }

    start_color();

    while (1)
    {
        switch(menu()){
            case 0: 
                game();
            break;
            case 1:
                editeur();
            break;
            case 2:
                endwin();
                return 1;
            default:
                endwin();
                return 1;
            break;
        }
        refresh();
    }
    
    
    getch();

    endwin();
    return 1;
}