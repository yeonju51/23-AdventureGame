#ifndef TOOLS_H
#define TOOLS_H

int dice();

int statsCheck(int playerStats, int diceRoll);

int getRandMonster(int monster_lev);

void checkForExit(const char* check);

void title(const char* title);

#endif // TOOLS_H