#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "global.h"
#include "tools.h"

void initPlayerName()
{
    printf("Please enter your characters name: ");
    fgets(player1.charname, STR_SIZE, stdin);
    printf("Your charachters name is %s", player1.charname);
}

void initPlayerStats()
{
    title("Allocate Your Ability Points");

    int charPoints = 10;

    printf("You have %d points to allocate for strength, agility and inteligence.", charPoints);

    while (checkVal == 0)
    {
        printf("\nPlease enter the amount of points to allocate for %s, min 1 point.", playerValues[0]);
        printf("\nIf you want to exit the game, type 'f' and press enter.\n"); // 종료하고싶으면 f를 누르라는 안내문 
        scanf_s("%s", str, STR_SIZE);
        checkForExit(str);  // 종료를 위한 특정 문자가 입력되었는지 확인하는 함수, 조금 더 클린한 코드를 위해서 const를 추가함

        val = atoi(str);
        checkVal = val;

        if (val > 0)
        {
            if (charPoints >= val)
            {
                player1.stre = val;
                charPoints = (charPoints - checkVal);
            }
            else
            {
                printf("You only have %d points left to allocate.\n", charPoints);
                checkVal = reset;
            };
        };
    };

    if (!charPoints)
    {
        printf("\nYou didnt spend any points in %s. Your hero fails to grasp the concept of getting out of bed. \n", playerValues[2]);
        printf("Your adventure ends before it even got started.\n");
        exit(0);
    };

    checkVal = reset;
    val = reset;

    printf("You character now have %d in %s .\n", player1.stre, playerValues[0]);
    printf("You have %d points left to allocate. \n", charPoints);

    while (checkVal == 0)
    {
        printf("\nPlease enter the amount of points to allocate for %s min 1.", playerValues[1]);
        printf("\nIf you want to exit the game, type 'f' and press enter.\n"); //종료하고싶으면 f를 누르라는 안내문
        scanf_s("%s", str, 20);
        checkForExit(str);  //종료를 위한 특정 문자가 입력되었는지 확인하는 함수  
        val = atoi(str);
        checkVal = val;
        if (val > 0)
        {
            if (charPoints >= val)
            {
                player1.agi = val;
                charPoints = (charPoints - checkVal);
                printf("You character now have %d in %s.\n", player1.agi, playerValues[1]);
                printf("You have %d points left to allocate. \n", charPoints);
            }
            else
            {
                printf("You only have %d points left to allocate. \n", charPoints);
                checkVal = reset;
            };
        };
    };

    if (!charPoints)
    {
        printf("\nYou didnt spend any points in %s. Your hero fails to grasp the concept of getting out of bed. \n", playerValues[2]);
        printf("Your adventure ends before it even got started. \n");
        exit(0);
    };

    checkVal = reset;
    val = reset;

    while (checkVal == 0)
    {
        printf("\nPlease enter the amount of points to allocate for %s min 1.", playerValues[2]);
        printf("\nIf you want to exit the game, type 'f' and press enter.\n"); //종료하고싶으면 f를 누르라는 안내문
        scanf_s("%s", str, 20);
        checkForExit(str);  //종료를 위한 특정 문자가 입력되었는지 확인하는 함수  
        val = atoi(str);
        checkVal = val;
        if (val > 0)
        {
            if (charPoints >= val)
            {
                player1.intel = val;
                charPoints = (charPoints - checkVal);
                printf("You character now have %d in %s.\n", player1.intel, playerValues[2]);
            }
            else
            {
                printf("You only have %d points left to allocate.\n", charPoints);
                checkVal = reset;
            };
        };
    };

    if (charPoints != 0)
    {
        printf("You didnt spend all your points. To bad for you.");
    };
}