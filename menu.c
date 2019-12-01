#include <ncurses.h>
#include <stdlib.h>

int menu(){

    char* choices[] = {
        "Game",
        "Editeur",
        "Exit"
    };
    int nb_choices = sizeof(choices) / sizeof(char *);
    int ch = 0;
    int choice = 0;
    
    while(1){
        

        switch (ch)
        {
        case KEY_DOWN:
            if(choice == nb_choices -1){
                choice = 0;
            }else
                choice ++;
            break;
        case KEY_UP:
            if(choice == 0){
                choice = nb_choices;
            }
                choice --;
            break;  
        case 10: // touche entrer
            return choice;
            break;
        default:
            break;
        }

        

        for(int i = 0; i < nb_choices; i++){
            if(i == choice){
                attron(A_REVERSE);
                mvaddstr(5+ i, 5, choices[i]);
                attroff(A_REVERSE);
            }else
                mvaddstr(5+ i, 5, choices[i]);
        }
        ch = getch();
    }

    refresh();

    //getch();

    return 1;


}