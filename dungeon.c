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
    int path;
    int trapCheck;

    while (checkVal == 0)
    {
        printf("Which way do you choose?\n");
        printf("1. Go forward\n");
        printf("2. Go left\n");
        printf("3. Go right\n");
        printf("Please enter choiche 1-3.\n");
  
        printf("If you want to exit the game, type 'f' and press enter.\n");
        fgets(str, STR_SIZE, stdin);

        checkForExit(str);

        val = atoi(str);
        checkVal = val;

        // 적절치 않은 값을 입력했을 때
        if (val < 0 || val > 3)
        {
            printf("Invalid Value: choose path again.\n");
            checkVal = reset;
        }
        else
        {
            path = val;
        }
    }


    switch (path)
    {
        // forward
        case (1):
            printf("\nYou choose the tunnel leading forward into the dungeon.\n");
            printf("The tunnel descends depper into the dungeon.\n");
            printf("You need to roll for an inteligence check.\n");

            playerDice = dice();
            printf("You rolled %d.\n", playerDice);

            trapCheck = statsCheck(playerDice, player1.stats[intel]);
            
            // 함정에 걸리고 게임 종료
            if (trapCheck == 1)
            {
                printf("\nYou failed to spot the hiden trap.\n");
                printf("You take an arrow to the knee.\n");
                printf("And with that your adventuring days are over. You limp out of the dungeon.\n");
                exit(0);
            }

            // 함정 돌파 성공
            else
            {
                printf("\nYou spot and disable a hidden trap.\n");
            }

            break;

        // left
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
                
                // 종료
                printf("If you want to exit the game, type 'f' and press enter.\n");
                fgets(str, STR_SIZE, stdin);
                checkForExit(str);

                val = atoi(str);
                checkVal = val;

                // 적절치 않은 값을 입력했을 때
                if (val < 0 || val > 2)
                {
                    printf("Invalid Value: choose path again.\n");
                    checkVal = reset;
                    continue;
                }
                else
                {
                    obstacle = val;
                }
            }

            switch (obstacle)
            {
                // 문을 발로 찰 때
                case (1):
                    printf("\nYou kick the door with all your might in an attempt to break it down.\n");
                    printf("The door wasnt locked.\n");

                    // 구덩이에 빠져 게임 종료
                    printf("The door opens and you tumble down into the spike filled pit hidden behind the door.\n");
                    printf("Enjoy your new career as a pincushion.\n");
                    printf("Your adventure ends here.\n");
                    exit(0);
                
                // 문 잠금을 해제하려고 할 때
                case (2):
                    printf("\nYou bend down to try to pick the lock only to notice that the door isnt locked.\n");
                    printf("You also noties the spike filled pit that is hidden behind the door.\n");
                    printf("You need to roll an agility check to see if you can avoid the pit.\n");

                    playerDice = dice();
                    printf("You rolled %d.\n", playerDice);
                    SLEEP(waitingTime);
                    trapCheck = statsCheck(playerDice, player1.stats[agi]);

                    // 구덩이를 뛰어넘는데 실패했을 때
                    if (trapCheck == 1)
                    {
                        printf("\nYou failed to jump over the pit.\n");
                        printf("Enjoy your new career as a pincushion.\n");
                        printf("Your adventure ends here.\n");
                        exit(0);
                    }
                    // 구덩이를 성공적으로 뛰어 넘을 때
                    else
                    {
                        printf("\nYou manage to safely jump over the pit.\n");
                        break;
                    }
            }

            break;

        // right
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

                // 종료
                printf("If you want to exit the game, type 'f' and press enter.\n");
                fgets(str, STR_SIZE, stdin);
                checkForExit(str); 

                val = atoi(str);
                checkVal = val;

                // 적절치 않은 값을 입력했을 때
                if (val < 0 || val > 2)
                {
                    printf("Invalid Value: choose path again.\n");
                    checkVal = reset;
                    continue;
                }
                else
                {
                    item = val;
                }
            }
            switch (item)
            {
                // 보물상자를 열 때
                case (1):
                    printf("\nYou open the chest and find a sword. When you lift it\n");
                    printf("you feel the power of the sword filling your body.\n");
                    printf("You picked up a magic sword that gives you +1 in strength.\n");

                    player1.stats[stre] += 1;
                    printf("Your strength is now %d .\n", player1.stats[stre]);
                    break;
                
                // 그냥 떠날 때
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

    // 난이도 선택
    printf("You venture deeper in to the dungeon.\n");
    printf("Please select the level of the monsters!\n1.Hard   2.Normal   3.Easy\n");


    // 난이도 입력

    fgets(str, STR_SIZE, stdin);

    int level = atoi(str);



    char* monster[MONSTER_COUNT] = { "thanos", "joker", "orc", "goblin", "mountain troll", "swarm of bats" }; // 몬스터 종류(난이도 세분화를 위해 thanos, joker 추가)
    int monsterStr[MONSTER_COUNT] = { 6, 5, 3, 3, 2, 1 }; // 몬스터 힘
    int monsterLife[MONSTER_COUNT] = { 4, 5, 4, 3, 2, 2 }; // 몬스터 HP

    // 몬스터 인카운터
    int encounter = getRandMonster(level);

    int playerStr = player1.stats[stre];
    int playerLife = 8;
    int playerTotal;

    char* encounterMonster = monster[encounter];
    int encounterMonsterStr = monsterStr[encounter];
    int encounterMonsterLife = monsterLife[encounter];
    int encounterMonsterTotal;

    printf("\nYou encountered a %s with %i strength and %i life.\n", encounterMonster, encounterMonsterStr, encounterMonsterLife);

    while (encounterMonsterLife > 0)
    {
        // 전투 전 정보 출력
        printf("\nYour strength: %d\n", playerStr);
        printf("Your life: %d\n", playerLife);
        printf("\n%s's strength: %d\n", encounterMonster, encounterMonsterStr);
        printf("%s's life: %d\n", encounterMonster, encounterMonsterLife);

        playerDice = dice();
        int monsterDice = dice();
        SLEEP(waitingTime);

        printf("\nYou roll %d on the dice.\n", playerDice);
        SLEEP(waitingTime);

        printf("The %s roll %d on the dice.\n", encounterMonster, monsterDice);
        SLEEP(waitingTime);

        // attack total 계산
        playerTotal = playerStr + playerDice;
        encounterMonsterTotal = encounterMonsterStr + monsterDice;
        printf("Your attack score is %d.\n", playerTotal);
        SLEEP(waitingTime);
        printf("The %s attack score is %d.\n", encounterMonster, encounterMonsterTotal);
        SLEEP(waitingTime);

        // player와 monster의 토탈 값을 비교
        if (playerTotal >= encounterMonsterTotal)
        {
            printf("You attack the %s sucesfully.\n", encounterMonster);
            encounterMonsterLife -= 1;
            SLEEP(waitingTime);
        }
        else
        {
            printf("Your attack fails and the %s hits you for one damage.\n", encounterMonster);
            playerLife -= 1;
            SLEEP(waitingTime);
            if (playerLife == 0)
            {
                printf("\nThe %s proved too much for you. Your adventure ends here.\n", encounterMonster);
                exit(0);
            }
        }

    };

    printf("\nYou managed to slay the %s.\n", encounterMonster);
    printf("You slayed the monster but to no avail as there is no cake to be had.\n");
    printf("You leave the dungeon for a life as a turnip farmer.\n");
}
