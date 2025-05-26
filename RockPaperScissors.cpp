#include <cstdio>
#include "RockPaperScissors.h"

void RockPaperScissors::game_init() {
    printf("[%s] game_init() 호출됨\n", game_title_str);
}

void RockPaperScissors::game_start() {
    printf("[%s] game_start() 호출됨\n", game_title_str);
    printf("키를 입력하세요. (가위,바위,보,종료)=(1,2,3,q)\n");
}

void RockPaperScissors::game_over() {
    printf("[%s] game_over() 호출됨\n", game_title_str);
}

void RockPaperScissors::key_input(int key_code) {
    printf("[%s] 캐비닛으로부터 입력 받은 키 값 (%d) : ", game_title_str, key_code);
    switch (key_code) {
    case '1': printf("가위!\n"); break;
    case '2': printf("바위!\n"); break;
    case '3': printf("보!\n"); break;
    case 'q': game_over(); break;
    default: break;
    }
}
