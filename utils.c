#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "playerinfo.h"

int getIntInput() {
    char input[STR_SIZE];
    int value;

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // 개행 문자 제거

        // 문자열이 숫자로 변환 가능한지 확인
        if (isNumeric(input)) {
            value = atoi(input);
            break;
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    }

    return value;
}

int isNumeric(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}
