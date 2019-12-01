#include <stdlib.h>
#include "define.h"
#include "file.h"


int loadFile(Map* gameMap){
    FILE* mapFile = NULL;

    int ch = '/';
    int x = 0;
    int y = 0;

    mapFile = fopen(FILE_NAME, "r");

    if(mapFile == NULL){
        return -1;
    }

    
    for(int y = 0; y < NB_BLOC_Y; y++){
        for(int x = 0; x < NB_BLOC_X; x++){
            fread(&ch, sizeof(char), 1, mapFile);
            switch (ch)
            {
            case '/':
                gameMap->map[x][y] = MUR;
                break;
            case '*':
                gameMap->map[x][y] = OBJECTIF;
                break;
            case 'm':
                gameMap->map[x][y] = MARIO;
                gameMap->positionM.x = x;
                gameMap->positionM.y = y;
                break;
            case 'c':
                gameMap->map[x][y] = CAISSE;
                break;
            }
            
        }
    }

    fclose(mapFile);
    return 1;
}


int save(Map *map){
    FILE* mapFile = NULL;

    int ch = '/';
    int x = 0;
    int y = 0;

    mapFile = fopen(FILE_NAME, "w");

    if(mapFile == NULL){
        return -1;
    }

    
    for(int y = 0; y < NB_BLOC_Y; y++){
        for(int x = 0; x < NB_BLOC_X; x++){
            // fread(&ch, sizeof(char), 1, mapFile);
            switch (map->map[x][y])
            {
            case VIDE:
                ch = ' ';
                break;
            case OBJECTIF:
                ch = '*';
                break;
            case MARIO:
                ch = 'm';
                break;
            case CAISSE:
                ch = 'c';
                break;
            case MUR:
                ch = '/';
                break;
            }
            fputc(ch ,mapFile);
            
        }
    }

    fclose(mapFile);
    return 1;
}