#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
#include <windows.h> // 윈도우 환경에서 Sleep 함수를 사용하기 위한 헤더 파일
#define SLEEP(x) Sleep(1000 * (x)) // 윈도우 환경에서는 Sleep 함수 사용, 밀리초 단위
#else
#include <unistd.h> // 유닉스 계열 운영체제에서 sleep 함수를 사용하기 위한 헤더 파일
#include <sys/time.h> //유닉스 계열 운영체제에서 gettimeofday 함수를 사용하기 위한 헤더 파일
#define SLEEP(x) sleep(x)
#endif

#endif // UTILS_H