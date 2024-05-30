#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "global.c"

int dice();
int monsterEncounter();
int statsCheck(int playerStats, int diceRoll);
void welcome();

void welcome() {
    char title[STR_SIZE] = "Welcome to this text based adventure game";
    printf("%55.55s\n", title);
}        

int dice() {
    int dice;
    time_t t;
    srand(time(&t));
    dice = (rand() % (DICE_FACE - 1)) + 1;
    return dice;
}

int monsterEncounter() {
    int monsterEncounter;
    time_t t;
    srand(time(&t));   
    monsterEncounter = (rand() % (MONSTER_COUNT - 1)) + 1;    
    return monsterEncounter;
}

int statsCheck(int playerStats, int diceRoll) {
    int result;
    result = 1;
    if (playerStats < diceRoll) {
        result = 0; 
    }
    return result;
}