#ifndef __FTG_H__
#define __FTG_H__
#include <stdbool.h>

struct character
{
    char name;
    int exp;
    int pv;
    int min_stat;
    int max_stat;
};

typedef struct character* game; //Crée un type game à partir de la structure character

bool win(game g);
void run(game g);
void inventory(game g);
void weapon(game g);
void monster_attack(game g);
bool attack(int * m_pv, game g);
void fight(game g);
game initStats(void);
void name(game g);

#endif