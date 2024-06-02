#include "player.h"
#include "dungeon.h"

#ifdef _WIN32
#include <windows.h> // 윈도우 환경에서 Sleep 함수를 사용하기 위한 헤더 파일
#else
#include <unistd.h> // 유닉스 계열 운영체제에서 sleep 함수를 사용하기 위한 헤더 파일
#include <sys/time.h> //유닉스 계열 운영체제에서 gettimeofday 함수를 사용하기 위한 헤더 파일
#endif

// sleep 함수를 호출하는 매크로 정의
#ifndef SLEEP
#ifdef _WIN32
#define SLEEP(x) Sleep(1000 * (x)) // 윈도우 환경에서는 Sleep 함수 사용, 밀리초 단위
#else
#define SLEEP(x) sleep(x) // 유닉스 계열 운영체제에서는 sleep 함수 사용, 초 단위
#endif
#endif

int main(int argc, char** argv)
{
    title("Welcome to this text based adventure game");

    initPlayerName();

    initPlayerStats();

    choosePath();

    encounterMonster();

    return 0;
}

int monsterEncounter(int monster_lev) //입력한 난이도 받기
{
    int monsterCount = 0;
    // 시간을 더 세분화하여 시드 값을 만듦
 
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