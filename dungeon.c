#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dungeon.h"
#include "global.h"
#include "tools.h"
#include "utils.h"

void choosePath()
{
    title("Entering the Dungeon");
    printf("You stand at the entrance of the dungeon. A big sign proclaims, There will be cake!\n");
    printf("You can go forward,left or right.\n");

    checkVal = reset;
    int path = 0;
    int trapCheck;
    while (checkVal == 0)
    {
        printf("Which way do you choose?\n");
        printf("1. Go forward\n");
        printf("2. Go left\n");
        printf("3. Go right\n");
        printf("Please enter choiche 1-3.\n");
        printf("If you want to exit the game, type 'f' and press enter.\n"); // 종료하고싶으면 f를 누르라는 안내문
        scanf_s("%s", str, STR_SIZE);
        checkForExit(str); // 종료를 위한 특정 문자가 입력되었는지 확인하는 함수  
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
            printf("\nYou choose the tunnel leading forward into the dungeon.\n");
            printf("The tunnel descends depper into the dungeon.\n");
            printf("You need to roll for an inteligence check.\n");

            rollDice = diece();
            printf("You rolled %d.\n", rollDice);

            trapCheck = statsCheck(rollDice, player1.intel);
            if (trapCheck == 1)
            {
                printf("\nYou failed to spot the hiden trap.\n");
                printf("You take an arrow to the knee.\n");
                printf("And with that your adventuring days are over. You limp out of the dungeon.\n");
                exit(0);
            }
            else
            {
                printf("\nYou spot and disable a hidden trap.\n");
            }
            break;

        case (2):
            printf("\nYou choose the tunnel leading left into the dungeon.\n");
            printf("The tunnel is blocked by a massive door.\n");

            checkVal = reset;
            int obstacle = 0;
            while (checkVal == 0)
            {
                printf("What do you want to do?\n");
                printf("1. Try to break down the door.\n");
                printf("2. Try to pick the lock.\n");
                printf("If you want to exit the game, type 'f' and press enter.\n"); // 종료하고싶으면 f를 누르라는 안내문
                scanf_s("%s", str, STR_SIZE);
                checkForExit(str); // 종료를 위한 특정 문자가 입력되었는지 확인하는 함수  
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
                    printf("\nYou kick the door with all your might in an attempt to break it down.\n");
                    printf("The door wasnt locked.\n");
                    printf("The door opens and you tumble down into the spike filled pit hidden behind the door.\n");
                    printf("Enjoy your new career as a pincushion.\n");
                    printf("Your adventure ends here.\n");
                    exit(0);
                    break;
                case (2):
                    printf("\nYou bend down to try to pick the lock only to notice that the door isnt locked.\n");
                    printf("You also noties the spike filled pit that is hidden behind the door.\n");
                    printf("You need to roll an agility check to see if you can avoid the pit.\n");
                    rollDice = diece();
                    printf("You rolled %d.\n", rollDice);
                    trapCheck = statsCheck(rollDice, player1.agi);
                    if (trapCheck == 1)
                    {
                        printf("\nYou failed to jump over the pit.\n");
                        printf("Enjoy your new career as a pincushion.\n");
                        printf("Your adventure ends here.\n");
                        exit(0);
                    }
                    else
                    {
                        printf("\nYou manage to safely jump over the pit.\n");
                    }
                    break;
            }
            break;

        case (3):
            printf("\nYou choose the right tunnel into the dungeon.\n");
            printf("You walk deeper in to the dungeon until the tunnel ends and you find yourself.\n");
            printf("in a big room with a wooden chest in the middle.\n");
            checkVal = reset;
            int item = 0;
            while (checkVal == 0)
            {
                printf("What do you want to do?\n");
                printf("1. Try to open the chest\n");
                printf("2. Leave the chest alone\n");
                printf("If you want to exit the game, type 'f' and press enter.\n"); //종료하고싶으면 f를 누르라는 안내문
                scanf_s("%s", str, STR_SIZE);
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
                    printf("\nYou open the chest and find a sword. When you lift it\n");
                    printf("you feel the power of the sword filling your body.\n");
                    printf("You picked up a magic sword that gives you +1 in strength.\n");
                    player1.stre = (player1.stre + 1);
                    printf("Your strength is now %d . \n", player1.stre);
                    break;
                case (2):
                    printf("\nYou leave the chest alone.\n");
                    break;
            }
            break;
        };
}

void encounterMonster()
{
    title("Fight against monsters");
    printf("You venture deeper in to the dungeon.\n");
    printf("Please select the level of the monsters!\n1.Hard   2.Normal   3.Easy\n");  // 난이도를 선택하라는 출력문
    scanf_s("%s", str, STR_SIZE); // 난이도 입력
    int level = atoi(str); // 게임 난이도를 입력할 변수

    char* monster[MONSTER_COUNT] = { "thanos", "joker", "orc", "goblin", "mountain troll", "swarm of bats" }; // 난이도 세분화를 위한 몬스터 추가(thanos, joker)
    int monsterStrenght[MONSTER_COUNT] = { 6, 5, 3, 3, 2, 1 }; // 몬스터 스텟 세분화
    int monsterLife[MONSTER_COUNT] = { 4, 5, 4, 3, 2, 2 }; // 몬스터 생명 세분화

    int encounter = getRandMonster(level); // 입력한 값 함수에 보내기

    printf("\nYou encountered a %s with %i strength and %i life.\n", monster[encounter], monsterStrenght[encounter], monsterLife[encounter]);

    int playerStr = player1.stre;
    int totalPlayer;
    int monsterTotal;
    int playerLife = 8;
    int monsterAlive = monsterLife[encounter];
    int waitingTime = 1;
    while (monsterAlive > 0)
    {
        //전투 시작 전 정보 출력
        printf("\nYour strength: %d\n", playerStr);
        printf("Your life: %d\n", playerLife);
        printf("\n%s's strength: %d\n", monster[encounter], monsterStrenght[encounter]);
        printf("%s's life: %d\n", monster[encounter], monsterAlive);

        int dice1 = diece();
        SLEEP(waitingTime);
        int dice2 = diece();
        printf("\nYou roll %d on the dice.\n", dice1);
        SLEEP(waitingTime);
        printf("The %s roll %d on the dice.\n", monster[encounter], dice2);
        SLEEP(waitingTime);
        totalPlayer = playerStr + dice1;
        monsterTotal = monsterStrenght[encounter] + dice2;
        printf("Your attack score is %d.\n", totalPlayer);
        SLEEP(waitingTime);
        printf("The %s attack score is %d.\n", monster[encounter], monsterTotal);
        SLEEP(waitingTime);

        if (totalPlayer >= monsterTotal)
        {
            printf("You attack the %s sucesfully.\n", monster[encounter]);
            SLEEP(waitingTime);
            monsterAlive -= 1;
        }
        else
        {
            printf("Your attack fails and the %s hits you for one damage.\n", monster[encounter]);
            playerLife -= 1;
            printf("Your life is %d.\n", playerLife);
            SLEEP(waitingTime);
            if (playerLife == 0)
            {
                printf("\nThe %s proved too much for you. Your adventure ends here.\n", monster[encounter]);
                exit(0);
            }
        }

    };

    printf("\nYou managed to slay the %s.\n", monster[encounter]);
    printf("You slayed the monster but to no avail as there is no cake to be had.\n");
    printf("You leave the dungeon for a life as a turnip farmer.\n");
}