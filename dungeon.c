#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dungeon.h"
#include "global.h"
#include "tools.h"
#include "utils.h"

void choosePath()
{
    separator();
    title("Entering the Dungeon");
    printf("You stand at the entrance of the dungeon. A big sign proclaims, There will be cake! \n");
    printf("You can go forward,left or right. \n");

    checkVal = reset;
    int path = 0;
    //int checkPath = 0;
    while (checkVal == 0)
    {
        printf("Which way do you choose? \n");
        printf("1. Go forward \n");
        printf("2. Go left \n");
        printf("3. Go right \n");
        printf("Please enter choiche 1-3 \n");
        printf("If you want to exit the game, type 'f' and press enter.\n"); //종료하고싶으면 f를 누르라는 안내문
        scanf_s("%s", str, 20);
        checkForExit(str);  //종료를 위한 특정 문자가 입력되었는지 확인하는 함수  
        val = atoi(str);
        checkVal = val;
        if (val > 0)
        {
            if (val > 3)
            {
                checkVal = reset;
            }
            else
            {
                path = val;
            }
        }
    }

    switch (path)
    {
    case (1):
        title("Inside the Dungeon");
        printf("You choose the tunnel leading forward into the dungeon \n");
        printf("The tunnel descends depper into the dungeon \n");
        printf("You need to roll for an inteligence check \n");
        rollDice = diece();
        printf("You rolled %d \n", rollDice);
        trapCheck = statsCheck(rollDice, player1.intel);
        if (trapCheck == 1)
        {
            printf("You failed to spot the hiden trap. \n");
            printf(" You take an arrow to the knee. \n");
            printf("And with that your adventuring days are over. You limp out of the dungeon \n");
            separator();
            exit(0);
        }
        else
        {
            printf("You spot and disable a hidden trap \n");
            separator();
        }
        break;
    case (2):
        title("Inside the Dungeon");
        printf("You choose the tunnel leading left into the dungeon \n");
        printf("The tunnel is blocked by a massive door \n");

        checkVal = reset;
        int obstacle = 0;
        while (checkVal == 0)
        {
            printf("What do you want to do? \n");
            printf("1. Try to break down the door. \n");
            printf("2. Try to pick the lock. \n");
            printf("If you want to exit the game, type 'f' and press enter.\n"); //종료하고싶으면 f를 누르라는 안내문
            scanf_s("%s", str, 20);
            checkForExit(str);  //종료를 위한 특정 문자가 입력되었는지 확인하는 함수  
            val = atoi(str);
            checkVal = val;
            if (val > 0)
            {
                if (val > 2)
                {
                    checkVal = reset;
                }
                else
                {
                    obstacle = val;
                }
            }
        }
        switch (obstacle)
        {
        case (1):
            separator();
            printf("You kick the door with all your might in an attempt to break it down.\n");
            printf("The door wasnt locked \n");
            printf("The door opens and you tumble down into the spike filled pit hidden behind the door \n");
            printf("Enjoy your new career as a pincushion \n ");
            printf("Your adventure ends here \n ");
            exit(0);
            break;
        case (2):
            separator();
            printf("You bend down to try to pick the lock only to notice that the door isnt locked. \n");
            printf("You also noties the spike filled pit that is hidden behind the door. \n");
            printf("You need to roll an agility check to see if you can avoid the pit. \n");
            rollDice = diece();
            printf("You rolled %d \n", rollDice);
            trapCheck = statsCheck(rollDice, player1.agi);
            if (trapCheck == 1)
            {
                printf("You failed to jump over the pit. \n");
                printf("Enjoy your new career as a pincushion. \n ");
                printf("Your adventure ends here. \n ");
                exit(0);
            }
            else
            {
                printf("You manage to safely jump over the pit \n");
                separator();
            }
            break;
        }
        break;

    case (3):
        separator();
        printf("You choose the right tunnel into the dungeon \n");
        printf("You walk deeper in to the dungeon until the tunnel ends and you find yourself \n");
        printf("in a big room with a wooden chest in the middle \n");
        checkVal = reset;
        int item = 0;
        while (checkVal == 0)
        {
            printf("What do you want to do ? \n");
            printf("1. Try to open the chest \n");
            printf("2. Leave the chest alone \n");
            printf("If you want to exit the game, type 'f' and press enter.\n"); //종료하고싶으면 f를 누르라는 안내문
            scanf_s("%s", str, 20);
            checkForExit(str);  //종료를 위한 특정 문자가 입력되었는지 확인하는 함수  
            val = atoi(str);
            checkVal = val;
            if (val > 0)
            {
                if (val > 2)
                {
                    checkVal = reset;
                }
                else
                {
                    item = val;
                }
            }
        }
        switch (item)
        {
        case (1):
            printf("You open the chest and find a sword. When you lift it \n");
            printf("you feel the power of the sword filling your body. \n");
            printf("You picked up a magic sword that gives you +1 in strength.  \n");
            player1.stre = (player1.stre + 1);
            printf("Your strength is now %d . \n", player1.stre);
            break;
        case (2):
            printf("You leave the chest alone.  \n");
            break;
        }

        break;
    };
}

void encounterMonster()
{
    separator();
    printf("You venture deeper in to the dungeon.   \n");
    title("Fight against monsters");
    printf("\n Please select the level of the monsters!   1.Hard   2.Normal   3.Easy...   \n");  //난이도를 선택하라는 출력문
    scanf_s("%s", str, STR_SIZE); //난이도 입력
    int encounter = getRandMonster(level);  //입력한 값 함수에 보내기

    printf("\n You encountered a %s with %i strength and %i life . \n", monster[encounter], monsterStrenght[encounter], monsterLife[encounter]);

    int playerStr = player1.stre;
    int totalPlayer;
    int monsterTotal;
    int playerLife = 8;
    int monsterAlive = monsterLife[encounter];
    while (monsterAlive > 0)
    {
        printf("Your strength: %d\n", playerStr);  //전투 시작 전 정보 출력
        printf("Your life: %d\n\n", playerLife);
        printf("%s's strength: %d\n", monster[encounter], monsterStrenght[encounter]);
        printf("%s's life: %d\n\n", monster[encounter], monsterAlive);
        int dice1 = diece();
        SLEEP(1);
        int dice2 = diece();
        printf("You roll %d on the dice, \n", dice1);
        SLEEP(2);
        printf("The %s roll %d on the dice \n", monster[encounter], dice2);
        SLEEP(2);
        totalPlayer = playerStr + dice1;
        monsterTotal = monsterStrenght[encounter] + dice2;
        printf("Your attack score is %d, \n", totalPlayer);
        SLEEP(2);
        printf("The %s attack score is %d, \n", monster[encounter], monsterTotal);
        SLEEP(2);

        if (totalPlayer >= monsterTotal)
        {
            printf("You attack the %s sucesfully \n", monster[encounter]);
            SLEEP(1);
            monsterAlive = (monsterAlive - 1);
        }
        else
        {
            printf("Your attack fails and the %s hits you for one damage .\n", monster[encounter]);
            playerLife = (playerLife - 1);
            printf("Your life is %d \n", playerLife);
            SLEEP(2);
            if (playerLife == 0)
            {
                printf("The %s proved too much for you. Your adventure ends here . \n", monster[encounter]);
                exit(0);
            }
        }

    };

    separator();
    printf("You managed to slay the %s \n", monster[encounter]);
    printf("You slayed the monster but to no avail as there is no cake to be had. \n");
    printf("You leave the dungeon for a life as a turnip farmer. \n");
}