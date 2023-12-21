#ifndef PLAYER_H_H
#define PLAYER_H_H

#define START_HEALTH 100
#define START_HUNGER 100

#include "area.h"

typedef struct Stat Stat;
struct Stat {
    char * name;
    int value;
    int max;
};

typedef struct Player Player;
struct Player {
    char name[20];
    Stat hunger;
    Stat health;
};

void stat_init(Stat * stat, char * name, int max);
void stat_display(Stat * stat);
void stat_add(Stat* stat, int amount);

void player_init(Player * player);
void player_display(Player * player);
int player_is_alive(Player * player);

#endif