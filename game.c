#include "game.h"
#include "file.h"


int game(){
    Map gameMap;
    int ch = 0;
    int go = 1;
    int move;

    init_pair(MARIO, COLOR_BLACK, COLOR_RED);

    initMap(&gameMap);

    keypad(gameMap.win , true);

    while (go == 1 && ch != 27)
    {
        
        switch (ch)
        {
        case KEY_DOWN:
            move = DOWN;
            break;
        case KEY_UP:
            move = UP;
            break;
        case KEY_LEFT:
            move = LEFT;
            break;
        case KEY_RIGHT:
            move = RIGHT;
            break;
        case 27:
            go = 0;
            break;
        default:
            move = RIEN;
            break;
        }
        mouveM(&gameMap, move);
        print_map(&gameMap);
        wrefresh(gameMap.win);
        ch = getch();
    }
    
    freeMap(&gameMap);

}




void initMap(Map *map){
    for(int x = 0; x < NB_BLOC_X; x++){
        for(int y = 0; y < NB_BLOC_Y; y++){
            map->map[x][y] = VIDE;
        }
    }
    loadFile(map);
    map->win = newwin(NB_BLOC_Y, NB_BLOC_X, 0, 0);
    
}


void freeMap(Map* map){
    for(int x = 0; x < NB_BLOC_X; x++){
        for(int y = 0; y < NB_BLOC_Y; y++){
            mvwaddch(map->win, y, x, ' ');
        }
    }
    wrefresh(map->win);
    delwin(map->win);
}


void print_map(Map *map){
    for(int x = 0; x < NB_BLOC_X; x++){
        for(int y = 0; y < NB_BLOC_Y; y++){
            switch (map->map[x][y])
            {
            case MUR:
                wattron(map->win, A_REVERSE);
                mvwaddch(map->win, y, x, ' ');
                wattroff(map->win, A_REVERSE);
                break;
            case MARIO:
                wattron(map->win, COLOR_PAIR(MARIO));
                mvwaddch(map->win, y, x, ' ');
                wattroff(map->win, COLOR_PAIR(MARIO));
                break;
            case VIDE:
                mvwaddch(map->win, y, x, ' ');
                break;
            case OBJECTIF:
                mvwaddch(map->win, y, x, '*');
                break;
            case CAISSE:
                mvwaddch(map->win, y, x, 'Q');
                break;
            case CAISSE_OK:
                mvwaddch(map->win, y, x, 'O');
                break;
            default:
                break;
            }
        }
    }
}


void mouveM(Map *map, int move){

    Coordonne temp = map->positionM;
    map->map[temp.x][temp.y] = VIDE;

    switch (move)
    {
    case RIGHT:
        if(map->map[temp.x + 1][temp.y] == VIDE){
            map->positionM.x ++;
        }else if (map->map[temp.x + 1][temp.y] == CAISSE)
        {
            if(map->map[temp.x + 2][temp.y] == VIDE){
                map->map[temp.x + 2][temp.y] = CAISSE;
                map->positionM.x ++;
            }else if (map->map[temp.x + 2][temp.y] == OBJECTIF)
            {
                map->map[temp.x + 2][temp.y] = CAISSE_OK;
                map->positionM.x ++;
            }            
        }        
        break;
    case LEFT:
        if(map->map[temp.x - 1][temp.y] == VIDE){
            map->positionM.x --;
        }else if (map->map[temp.x - 1][temp.y] == CAISSE)
        {
            if(map->map[temp.x - 2][temp.y] == VIDE){
                map->map[temp.x - 2][temp.y] = CAISSE;
                map->positionM.x --;
            }else if (map->map[temp.x - 2][temp.y] == OBJECTIF)
            {
                map->map[temp.x - 2][temp.y] = CAISSE_OK;
                map->positionM.x --;
            }            
        }        
        break;
    case UP:
        if(map->map[temp.x][temp.y - 1] == VIDE){
            map->positionM.y --;
        }else if (map->map[temp.x][temp.y - 1] == CAISSE)
        {
            if(map->map[temp.x][temp.y - 2] == VIDE){
                map->map[temp.x][temp.y - 2] = CAISSE;
                map->positionM.y --;
            }else if (map->map[temp.x][temp.y - 2] == OBJECTIF)
            {
                map->map[temp.x][temp.y - 2] = CAISSE_OK;
                map->positionM.y --;
            }            
        } 
        break;
    case DOWN:
        if(map->map[temp.x][temp.y + 1] == VIDE){
            map->positionM.y ++;
        }else if (map->map[temp.x][temp.y + 1] == CAISSE)
        {
            if(map->map[temp.x][temp.y + 2] == VIDE){
                map->map[temp.x][temp.y + 2] = CAISSE;
                map->positionM.y ++;
            }else if (map->map[temp.x][temp.y + 2] == OBJECTIF)
            {
                map->map[temp.x][temp.y + 2] = CAISSE_OK;
                map->positionM.y ++;
            }            
        } 
        break;    
    default:
        break;
    }

    map->map[map->positionM.x][map->positionM.y] = MARIO;
}
