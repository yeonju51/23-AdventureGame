#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diece()
{
    int dice;
    dice = (rand() % 5) + 1;
    return dice;
}

int statsCheck(int playerStats, int diceRoll)
{
    int result;
    result = 1;
    if (playerStats < diceRoll)
    {
        result = 0;
    }
    return result;
}

// 구분선 출력
void separator()
{
    printf("--------------------------------------------------------\n");
}

void checkForExit(const char* check)  
{
    if (*check == 'f' || *check == 'F') {
        printf("You chose to exit the game. Goodbye!\n");
        exit(0);
    }
}

void title(const char* title)
{
    printf("\n\n");
    printf("********** %s **********\n\n", title);
}