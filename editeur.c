#include "editeur.h"
#include "game.h"

int editeur(){

    Map gameMap;
    int ch = 0;
    int go = 1;
    int move;
    int bloc_behind = VIDE;

    init_pair(MARIO, COLOR_BLACK, COLOR_RED);

    initMap(&gameMap);

    keypad(gameMap.win , true);

    while (go == 1 && ch != 27)
    {
        
        switch (ch)
        {
        case KEY_DOWN:
            gameMap.map[gameMap.positionM.x][gameMap.positionM.y] = bloc_behind;
            gameMap.map[gameMap.positionM.x][gameMap.positionM.y + 1] = MARIO;
            gameMap.positionM.y += 1;
            break;
        case KEY_UP:
            gameMap.map[gameMap.positionM.x][gameMap.positionM.y] = bloc_behind;
            gameMap.map[gameMap.positionM.x][gameMap.positionM.y - 1] = MARIO;
            gameMap.positionM.y -= 1;
            break;
        case KEY_LEFT:
            gameMap.map[gameMap.positionM.x][gameMap.positionM.y] = bloc_behind;
            gameMap.map[gameMap.positionM.x - 1][gameMap.positionM.y] = MARIO;
            gameMap.positionM.x -= 1;
            break;
        case KEY_RIGHT:
            gameMap.map[gameMap.positionM.x][gameMap.positionM.y] = bloc_behind;
            gameMap.map[gameMap.positionM.x + 1][gameMap.positionM.y] = MARIO;
            gameMap.positionM.x += 1;
            break;
        case 27:
            go = 0;
            break;
        default:
            move = RIEN;
            switch (ch)
            {
                case 'v':
                    bloc_behind = VIDE;
                    break;
                case 'm':
                    bloc_behind = MUR;     
                    break;
                case 'c':
                    bloc_behind = CAISSE;
                    break;
                case 'o':
                    bloc_behind = OBJECTIF;
                    break;
                case 's':
                    save(&gameMap);
            }
            break;
        }
        mouveM(&gameMap, move);
        print_map(&gameMap);
        wrefresh(gameMap.win);
        ch = getch();
    }
    
    freeMap(&gameMap);

    
}