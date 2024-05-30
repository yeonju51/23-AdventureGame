#include "playerinfo.h"

#define STR_SIZE 100
#define PLAYER_STAT_COUNT 3
#define MONSTER_COUNT 4
#define MONSTER_STAT_VALUE_COUNT 4
#define DICE_FACE 6

struct playerInfo player;
char * statsName[PLAYER_STAT_COUNT] = {"Strength", "Agility", "Inteligence"};
char * monster[MONSTER_COUNT] = {"Orc", "Goblin", "Mountain Troll", "Swarm of Bats"};
int monsterStrengh[MONSTER_STAT_VALUE_COUNT] = {3, 2, 5, 1};
int monsterLife[MONSTER_STAT_VALUE_COUNT] = {3, 2, 4, 1};

int rollDice;
int trapCheck;