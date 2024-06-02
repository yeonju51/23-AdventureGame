#ifndef GLOBAL_H
#define GLOBAL_H

#include "playerinfo.h"

#define DICE_FACE 6
#define MONSTER_COUNT 6

struct playerInfo player1;
char* playerValues[PLAYER_STATS_COUNT];
int playerDice;

int waitingTime;

int val;
int checkVal;
int reset;
char str[STR_SIZE];

#endif // GLOBAL_H