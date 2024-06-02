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

int main(){
    test_dice();
}
