#include "playerinfo.h"

#define PLAYER_STATS_COUNT 3
#define MONSTER_COUNT 6

int rollDice;
int trapCheck;

struct playerInfo player1;
char* playerValues[PLAYER_STATS_COUNT] = { "Strength", "Agility", "Inteligence" };

char* monster[MONSTER_COUNT] = { "thanos", "joker", "orc", "goblin", "mountain troll", "swarm of bats" }; // 난이도를 세분화를 위한 몬스터 추가(thanos, joker)
int monsterStrenght[MONSTER_COUNT] = { 6, 5, 3, 3, 2, 1 }; // 몬스터 스텟 세분화
int monsterLife[MONSTER_COUNT] = { 4, 5, 4, 3, 2, 2 }; // 몬스터 생명 세분화