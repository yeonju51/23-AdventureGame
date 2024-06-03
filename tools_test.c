#include <stdio.h>
#include <assert.h>

#include "tools.h"
#include "global.h"


//dice 함수 테스트
void test_dice() 
{
    int result = dice();
    // 주사위 값은 1에서 DICE_FACE 사이
    assert(result >= 1 && result <= DICE_FACE);
    printf("dice function test 성공!\n");
}

//statsCheck 함수 테스트

void test_statsCheck() 
{
    // 플레이어 스탯 >= 주사위
    assert(statsCheck(5, 3) == 1); // 테스트 통과
    assert(statsCheck(3, 3) == 1); // 테스트 통과

    // 플레이어 스탯 < 주사위 
    assert(statsCheck(3, 5) == 0); // 테스트 통과
    assert(statsCheck(2, 4) == 0); // 테스트 통과
    printf("statsCheck function test 성공!\n");

}

// getRandMonster 함수 테스트
void test_getRandMonster() 
{
    // 난이도가 1인 경우 -> 0 or 1
    int result1 = getRandMonster(1);
    assert(result1 >= 0 && result1 <= 1);

    // 난이도가 2인 경우 -> 2 or 3
    int result2 = getRandMonster(2);
    assert(result2 >= 2 && result2 <= 3);

    // 난이도가 3인 경우 -> 4 or 5
    int result3 = getRandMonster(3);
    assert(result3 >= 4 && result3 <= 5);

    printf("getRandMonster function test 성공!\n");
}


// checkForExit 함수 테스트
void test_checkForExit() 
{

    // 'f' 또는 'F' 이외의 문자가 입력된 경우
    char input1[] = "a";
    checkForExit(input1); // 함수 실행

    printf("checkForExit function test 성공!\n");

    // 'f'가 입력된 경우
    char input2[] = "f";
    checkForExit(input2); // 함수 실행


}

int main()
{
    test_dice();
    test_statsCheck();
    test_getRandMonster();
    test_checkForExit();
}
