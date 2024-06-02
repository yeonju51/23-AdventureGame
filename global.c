#include "playerinfo.h"

#include "global.h"

int rollDice = 0;

struct playerInfo player1;
char* playerValues[PLAYER_STATS_COUNT] = { "Strength", "Agility", "Inteligence" };

int val = 0;
int checkVal = 0;
int reset = 0;
char str[STR_SIZE] = "";