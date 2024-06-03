#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "global.h"
#include "tools.h"

// 플레이어 이름 설정
void initPlayerName()
{
    printf("Please enter your characters name: ");
    fgets(player1.charname, STR_SIZE, stdin);
    printf("Your charachters name is %s", player1.charname);
}

// 플레이어 스텟 설정
void initPlayerStats()
{
    title("Allocate Your Ability Points");

    int statPoints = 10; // 남은 스텟 포인트

    printf("You have %d points to allocate for %s, %s and %s.\n", statPoints, playerValues[0], playerValues[1],playerValues[2]);

    for (int i = 0; i < PLAYER_STATS_COUNT; i++)
    {
        while (checkVal == 0)
        {
            printf("\nPlease enter the amount of points to allocate for %s, min 1 point.\n", playerValues[i]);

            // 종료
            printf("If you want to exit the game, type 'f' and press enter.\n"); 
            fgets(str, STR_SIZE, stdin);
            checkForExit(str);

            val = atoi(str);
            checkVal = val;

            if (val > 0)
            {
                // 남은 스텟 포인트가 입력보다 클 때
                if (statPoints >= val)
                {
                    player1.stats[i] = val;
                    statPoints -= checkVal;
                    printf("You character now have %d in %s.\n", player1.stats[i], playerValues[i]);
                    printf("You have %d points left to allocate. \n", statPoints);
                }
                // 남은 스텟 포인트가 입력보다 작을 때
                else 
                {
                    printf("You only have %d points left to allocate.\n", statPoints);
                    checkVal = reset;
                    continue;
                }
            }

            // intel 스텟을 할당하기도 전에, 스텟 포인트를 모두 써버렸을 때
            if (!statPoints && i != PLAYER_STATS_COUNT - 1)
            {
                printf("\nYou didnt spend any points in %s. Your hero fails to grasp the concept of getting out of bed.\n", playerValues[2]);
                printf("Your adventure ends before it even got started.\n");
                exit(0);
            };
        }

        checkVal = reset;
        val = reset;

        // intel까지 스텟 할당을 마치고, 스텟 포인트가 남았을 때
        if (statPoints > 0 && i == PLAYER_STATS_COUNT - 1)
        {
            printf("\nYou didnt spend all your points. Too bad for you.");
        }
    }
}