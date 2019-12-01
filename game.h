#ifndef GAME_HEADER
#define GAME_HEADER

#include <ncurses.h>
#include <stdlib.h>
#include "define.h"




typedef struct Coordonne Coordonne;
typedef struct Map Map;
struct Coordonne
{
    int x;
    int y;
};


struct Map
{
    int map[NB_BLOC_X][NB_BLOC_Y];
    WINDOW *win;
    Coordonne positionM;

};


int game();
void initMap(Map *map);
void print_map(Map *map);

void mouveM(Map *map, int move);
void freeMap(Map* map);





#endif