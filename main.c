#ifdef _WIN32
#include <windows.h> // 윈도우 환경에서 Sleep 함수를 사용하기 위한 헤더 파일
#else
#include <unistd.h> // 유닉스 계열 운영체제에서 sleep 함수를 사용하기 위한 헤더 파일
#endif

// sleep 함수를 호출하는 매크로 정의
#ifdef _WIN32
#define SLEEP(x) Sleep(x) // 윈도우 환경에서는 Sleep 함수 사용 
#else
#define SLEEP(x) sleep(x) // 유닉스 계열 운영체제에서는 sleep 함수 사용 
#endif

#include "player.c"

int monsterEncounter(int level);

int main(int argc, char** argv)
{
    title("Welcome to this text based adventure game");

    initPlayerName();

    initPlayerStats();

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
    int choosePath = 0;
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
                choosePath = val;
            }
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
            printf(" You take an arrow to the knee. \n");
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
            return 1;
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

    /*
    * I am certain there is other ways of getting a random number generated then
    * the one I use in my function but this is the one I found and decided to use.
    * As to get the text to not scroll to fast I set a sleep so that the user have
    * time to read it also does so that at leat a second passes betwwen the calls to
    * the random function.
    */
    separator();
    printf("You venture deeper in to the dungeon.   \n");
    title("Fight against monsters");
    printf("\n Please select the level of the monsters!   1.Hard   2.Normal   3.Easy...   \n");  //난이도를 선택하라는 출력문
    scanf_s("%s", str, 20); //난이도 입력
    int encounter = monsterEncounter(level);  //입력한 값 함수에 보내기

    printf("\n You encountered a %s with %i strength and %i life . \n", monster[encounter], monsterStrenght[encounter],
        monsterLife[encounter]);

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

int monsterEncounter(int monster_lev) //입력한 난이도 받기
{
    int monsterCount = 0;
    // 시간을 더 세분화하여 시드 값을 만듦
    SYSTEMTIME st;
    GetSystemTime(&st);
    srand((unsigned int)(st.wMilliseconds));
    switch (monster_lev) {
    case 1:
        monsterCount = (rand() % 2);
        break;
    case 2:
        monsterCount = (rand() % 2) + 2;
        break;
    case 3:
        monsterCount = (rand() % 2) + 4;
        break;
    default:
        break;
    }
    return monsterCount;
}


