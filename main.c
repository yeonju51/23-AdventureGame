#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "playerinfo.h"
int diece();
int monsterEncounter();
int statsCheck(int playerStats, int diceRoll);
void separator();
void title(const char* title);
int main(int argc, char** argv)
{
    /*
*   Copyright (C) 2016 Oscar Ydrefelt
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License version 3 as published by
*   the Free Software Foundation.

*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   I wrote this program because I was curious about C and I wanted
*   to try it out and It was written mostly by trading Sleep for coding.
*   I am certain that there is tons of ways this code could be better and
*   if I have the time and continue to go down the path of C I might come
*   back to it.
*/


    int rollDice;
    int trapCheck;
    struct playerInfo player1;
    title("Welcome to this text based adventure game");
    char* monster[4] = { "orc","goblin","Mountain troll","swarm of bats" };
    char* playerValues[3] = { "strength","Agility","Inteligence" };
    int monsterStrenght[4] = { 3,2,5,1 };
    int monsterLife[4] = { 3,2,4,1 };

    printf("\n Please enter your characters name \n ");
    printf("name: ");
    fgets(player1.charname, 20, stdin);
    printf("Your charachters name is %s\n", player1.charname);

    /*
    * If the user enters more then 20 characters for the name it will spill
    * over and trigger an allocate points action. If I have time some day
    * I might look more into the fabulous world of user input.
    */

    int val;
    int checkVal = 0;
    int reset = 0;
    char str[20];
    int charPoints = 10;
    title("Allocate Your Ability Points");
    printf("\n You have %d points to allocate for strength, agility and inteligence. \n", charPoints);

    while (checkVal == 0)
    {
        printf("\nPlease enter the amount of points to allocate for %s, min 1 point. \n ", playerValues[0]);
        printf("%s: ", playerValues[0]);
        scanf_s("%s", str, sizeof(str));
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
                printf("You only have %d points left to allocate. \n", charPoints);
                checkVal = reset;
            };
        };
    };

    if (!charPoints)
    {
        printf("You didnt spend any points in %s. Your hero fails to grasp the concept of getting out of bed. \n", playerValues[2]);
        printf("Your adventure ends before it even got started. \n");
        return 1;
    };

    checkVal = reset;
    val = reset;
    printf("You character now have %d in %s .\n", player1.stre, playerValues[0]);
    printf("You have %d points left to allocate. \n", charPoints);
    while (checkVal == 0)
    {
        printf("\nPlease enter the amount of points to allocate for %s min 1. \n ", playerValues[1]);
        printf("%s: ", playerValues[1]);
        scanf_s("%s", str, sizeof(str));
        val = atoi(str);
        checkVal = val;
        if (val > 0)
        {
            if (charPoints >= val)
            {
                player1.agi = val;
                charPoints = (charPoints - checkVal);
                printf("You character now have %d in %s .\n", player1.agi, playerValues[1]);
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
        printf("You didnt spend any points in %s. Your hero fails to grasp the concept of getting out of bed. \n", playerValues[2]);
        printf("Your adventure ends before it even got started. \n");
        return 1;
    };


    checkVal = reset;
    val = reset;

    while (checkVal == 0)
    {
        printf("\nPlease enter the amount of points to allocate for %s min 1. \n ", playerValues[2]);
        printf("%s: ", playerValues[2]);
        scanf_s("%s", str, sizeof(str));
        val = atoi(str);
        checkVal = val;
        if (val > 0)
        {
            if (charPoints >= val)
            {
                player1.intel = val;
                charPoints = (charPoints - checkVal);
                printf("You character now have %d in %s .\n", player1.intel, playerValues[2]);

            }
            else
            {
                printf("You only have %d points left to allocate. \n", charPoints);
                checkVal = reset;
            };
        };
    };

    if (charPoints != 0)
    {
        printf("You didnt spend all your points. To bad for you. \n");

    };

    /*
     * I am certain that the whole points allocation could have been written in a more
     * efficent manner and that I should have pushed it to a function but at this stage I
     * am more concerned about getting it to work.
     *
    */

    /*
     * I use the case functionality because I thought it was a simple way of driving the
     * story of the game forward. It also makes you pay attention on opening and closing your
     * statements. And yes I should have pushed more stuff as functions.
    */
    separator();
    title("Entering the Dungeon");
    printf("You stand at the entrance of the dungeon. A big sign proclaims, There will be cake! \n");
    printf("You can go forward,left or right. \n");

    checkVal = reset;
    int choosePath;
    //int checkPath = 0;
    while (checkVal == 0)
    {
        printf("Which way do you choose? \n");
        printf("1. Go forward \n");
        printf("2. Go left \n");
        printf("3. Go right \n");
        printf("Please enter choiche 1-3 \n");
        printf("My choice: ");
        scanf_s("%s", str, sizeof(str));
        val = atoi(str);
        if (val >= 1 && val <= 3)
        {
            choosePath = val;
            checkVal = 1;
        }
        else
        {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
        }
    }

    switch (choosePath)
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
            printf("You take an arrow to the knee. \n");
            printf("And with that your adventuring days are over. You limp out of the dungeon \n");
            separator();
            return 1;
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
        int obstacle;
        while (checkVal == 0)
        {
            printf("What do you want to do? \n");
            printf("1. Try to break down the door. \n");
            printf("2. Try to pick the lock. \n");
            printf("My choice: ");
            scanf_s("%s", str, sizeof(str));
            val = atoi(str);
            if (val >= 1 && val <= 2)
            {
                obstacle = val;
                checkVal = 1;

            }
            else
            {
                printf("\nInvalid input. Please enter a number between 1 and 2.\n");
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
            title("Your adventure ends here.");
            return 1;
            break;
        case (2):
            separator();
            printf("You bend down to try to pick the lock only to notice that the door isnt locked. \n");
            printf("You also noties the spike filled pit that is hidden behind the door. \n");
            printf("You need to roll an agility check to see if you can avoid the pit. \n");
            rollDice = diece();
            printf("[ You rolled %d ]\n", rollDice);
            trapCheck = statsCheck(rollDice, player1.agi);
            if (trapCheck == 1)
            {
                printf("You failed to jump over the pit. \n");
                printf("Enjoy your new career as a pincushion. \n ");
                title("Your adventure ends here.");
                return 1;
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
        int item;
        while (checkVal == 0)
        {
            printf("What do you want to do ? \n");
            printf("1. Try to open the chest \n");
            printf("2. Leave the chest alone \n");
            printf("My choice: ");
            scanf_s("%s", str, sizeof(str));
            val = atoi(str);
            if (val >= 1 && val <= 2)
            {
                item = val;
                checkVal = 1;
            }
            else
            {
                printf("Invalid input. Please enter a number between 1 and 2.\n");
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

    /*
    * I am certain there is other ways of getting a random number generated then
    * the one I use in my function but this is the one I found and decided to use.
    * As to get the text to not scroll to fast I set a Sleep so that the user have
    * time to read it also does so that at leat a second passes betwwen the calls to
    * the random function.
    */
    separator();
    printf("You venture deeper in to the dungeon.   \n");
    int encounter = monsterEncounter();
    title("Fight against monsters");
    printf("\nYou encountered a %s with %i strength and %i life . \n", monster[encounter], monsterStrenght[encounter],
        monsterLife[encounter]);

    int playerStr = player1.stre;
    int totalPlayer;
    int monsterTotal;
    int playerLife = 8;
    int monsterAlive = monsterLife[encounter];
    while (monsterAlive > 0)
    {
        printf("Your strength: %d\n", playerStr);
        printf("Your life: %d\n\n", playerLife);
        printf("%s's strength: %d\n", monster[encounter], monsterStrenght[encounter]);
        printf("%s's life: %d\n\n", monster[encounter], monsterAlive);
        int dice1 = diece();
        Sleep(100);
        int dice2 = diece();
        printf("You roll %d on the dice, \n", dice1);
        Sleep(1000);
        printf("The %s roll %d on the dice \n", monster[encounter], dice2);
        Sleep(1000);
        totalPlayer = playerStr + dice1;
        monsterTotal = monsterStrenght[encounter] + dice2;
        printf("Your attack score is %d, \n", totalPlayer);
        Sleep(1000);
        printf("The %s attack score is %d, \n", monster[encounter], monsterTotal);
        Sleep(1000);

        if (totalPlayer >= monsterTotal)
        {
            printf("You attack the %s sucesfully \n\n", monster[encounter]);
            Sleep(1);
            monsterAlive = (monsterAlive - 1);
        }
        else
        {
            printf("Your attack fails and the %s hits you for one damage .\n\n", monster[encounter]);
            playerLife = (playerLife - 1);
            Sleep(1000);
            if (playerLife == 0)
            {
                printf("The %s proved too much for you. Your adventure ends here . \n", monster[encounter]);
                separator();
                return 1;
            }
        }

    };

    separator();
    printf("You managed to slay the %s \n", monster[encounter]);
    printf("You slayed the monster but to no avail as there is no cake to be had. \n");
    printf("You leave the dungeon for a life as a turnip farmer. \n");

    return 0;
}


int diece()
{
    int dice;
    time_t t;
    srand(time(&t));
    dice = (rand() % 5) + 1;
    return dice;
}

int monsterEncounter()
{
    int monsterEncounter;
    time_t t;
    srand(time(&t));
    monsterEncounter = (rand() % 3) + 1;
    return monsterEncounter;
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

void separator()
{
    printf("--------------------------------------------------------\n");
}

void title(const char* title)
{
    printf("\n\n");
    printf("********** %s **********\n\n", title);

}
