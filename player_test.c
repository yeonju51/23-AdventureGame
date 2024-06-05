#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "global.h"
#include "tools.h"

// initPlayerName 함수 테스트
void test_initPlayerName()
{
    char mock_input[] = "TestPlayer\n";
    FILE* fp = fmemopen(mock_input, strlen(mock_input), "r");
    if (fp == NULL) 
    {
        perror("Failed to open mock input");
        exit(EXIT_FAILURE);
    }
    stdin = fp; //표준 입력을 모의 입력으로 설정

    initPlayerName();

    fclose(fp);

    // 테스트 결과에 따라 출력
    if (strcmp(player1.charname, "TestPlayer\n") == 0) 
    {
        printf("test_initPlayerName PASSED\n");
    } 
    else 
    {
        printf("test_initPlayerName FAILED\n");
    }
}

// initPlayerStats 함수 테스트
void test_initPlayerStats() 
{
    char mock_input[] = "5\n3\n2\n";
    FILE* fp = fmemopen(mock_input, strlen(mock_input), "r");
    if (fp == NULL) 
    {
        perror("Failed to open mock input");
        exit(EXIT_FAILURE);
    }
    stdin = fp; // 표준 입력을 모의 입력으로 설정

    initPlayerStats();

    fclose(fp);

    // 테스트 결과에 따라 출력
    if (player1.stats[0] == 5 && player1.stats[1] == 3 && player1.stats[2] == 2) 
    {
        printf("test_initPlayerStats PASSED\n");
    } 
    else 
    {
        printf("test_initPlayerStats FAILED\n");
    }
}

int main() 
{
    test_initPlayerName();
    test_initPlayerStats();
    return 0;
}