#ifndef DEFINE_HEADER
#define DEFINE_HEADER


#define NB_BLOC_Y 16
#define NB_BLOC_X 32

#define FILE_NAME "map.txt"

typedef enum Obj Obj;
typedef enum Move Move;


enum Obj{
    VIDE, MUR, CAISSE, CAISSE_OK, MARIO, OBJECTIF
};


enum Move{
    UP, DOWN, RIGHT, LEFT, RIEN
};

#endif