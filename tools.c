#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tools.h"
#include "global.h"
#include "utils.h"

int dice()
{
    srand((unsigned int)time(NULL)); // 현재 시간을 이용하여 시드를 초기화합니다.
    int dice = (rand() % DICE_FACE) + 1; // 1부터 DICE_FACE까지의 랜덤한 값을 반환합니다.
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

int getRandMonster(int monster_lev) //입력한 난이도 받기
{
    int monster = 0; // 시간을 더 세분화하여 시드 값을 만듦
 
    #ifdef _WIN32
        SYSTEMTIME st;
        GetSystemTime(&st);
        srand((unsigned int)(st.wMilliseconds));
    #else
        struct timeval time;
        gettimeofday(&time, NULL);
        srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
    #endif

    switch (monster_lev) {
    case 1:
        monster = (rand() % 2);
        break;
    case 2:
        monster = (rand() % 2) + 2;
        break;
    case 3:
        monster = (rand() % 2) + 4;
        break;
    default:
        break;
    }
    return monster;
}

void checkForExit(const char* check)  
{
    if (*check == 'f' || *check == 'F') {
        printf("You chose to exit the game. Goodbye!\n");
        exit(0);
    } else {
        printf("Invalid input. Please enter 'f' to exit the game.\n");
        // 프로그램 종료하지 않고 다른 동작 수행
    }
}

void title(const char* title)
{
    printf("\n********** %s **********\n\n", title);
}