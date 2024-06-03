#include "playerinfo.h"
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

struct playerInfo player1;
char* playerValues[PLAYER_STATS_COUNT] = { "Strength", "Agility", "Intelligence" };
int playerDice = 0;

int waitingTime = 1;

int val = 0;
int checkVal = 0;
int reset = 0;
char str[STR_SIZE] = "";

