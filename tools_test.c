#include <stdio.h>
#include <assert.h> // assert 함수 사용을 위한 헤더
#include "global.h"
// 테스트할 함수가 정의된 헤더 파일
#include "tools.h"

// statsCheck 함수 테스트
void test_statsCheck() 
{
    // 테스트 케이스
    assert(statsCheck(5, 3) == 1); // 5 < 3 이므로 1 반환
    assert(statsCheck(3, 5) == 0); // 3 < 5 가 아니므로 0 반환
    assert(statsCheck(4, 4) == 1); // 4 < 4 가 아니므로 1 반환
    
    // 테스트 성공 메시지 출력
    printf("statsCheck function test successful\n");
}

// diece 함수 테스트
void test_diece() 
{
    int result = diece();
    // 주사위 값은 1에서 DICE_FACE 사이여야 합니다.
    assert(result >= 1 && result <= DICE_FACE);
    printf("diece function test successful\n");
}

// getRandMonster 함수 테스트
void test_getRandMonster() 
{
    int result = getRandMonster(1);
    // 난이도 1에서 몬스터 번호는 0에서 1 사이어야 합니다.
    assert(result >= 0 && result <= 1);

    result = getRandMonster(2);
    // 난이도 2에서 몬스터 번호는 2에서 3 사이어야 합니다.
    assert(result >= 2 && result <= 3);

    result = getRandMonster(3);
    // 난이도 3에서 몬스터 번호는 4에서 5 사이어야 합니다.
    assert(result >= 4 && result <= 5);

    printf("getRandMonster function test successful\n");
}

// checkForExit 함수 테스트
void test_checkForExit() 
{
    // 테스트 케이스: 'f'를 입력할 경우
    printf("Testing checkForExit function:\n");
    checkForExit("f");
    // 함수가 정상적으로 종료되는지 확인하기 위해 아래 코드는 실행되지 않습니다.
    printf("checkForExit function test successful\n");
}

// title 함수 테스트
void test_title() 
{
    // 테스트 케이스: 제목 출력 확인
    printf("Testing title function:\n");
    title("Test Title");
    // 이 함수는 출력 결과를 확인하기 위해 특별한 assert를 사용하지 않습니다.
}

int main() {
    // 각 함수에 대한 단위 테스트 실행
    test_statsCheck();
    test_diece();
    test_getRandMonster();
    test_checkForExit();
    test_title();
    return 0;
}
