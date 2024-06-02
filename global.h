#ifndef GLOBAL_H
#define GLOBAL_H

#include "playerinfo.h"

#define DICE_FACE 6
#define PLAYER_STATS_COUNT 3
#define MONSTER_COUNT 6
#define STR_SIZE 20

int rollDice;

struct playerInfo player1;
char* playerValues[PLAYER_STATS_COUNT];

int val;
int checkVal;
int reset;
char str[STR_SIZE];

#endif // GLOBAL_H