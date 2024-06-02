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


int main(){
    test_dice();
    test_statsCheck();

}
