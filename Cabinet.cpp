#include <cstdio>
#include <iostream>
#include "Cabinet.h"

//1.초기화면
//2.coininput
//3.게임 선택
//4.게임 시작
//4.게임오버
//5.게임 종료

// 3. 캐비닛 클래스 구현
/*
class Cabinet {
    const char* cabinet_model_str = "캐비닛 R123";
    IGame* installed_game = nullptr;
    bool is_running = false;
public:
    void hw_check() {
        printf("[%s] Cabinet 전원 체크, 롬 체크 등\n", cabinet_model_str);
    }
    void load_game(IGame* game) {
        installed_game = game;
    }
    void unload_game() {
        delete installed_game;
        installed_game = nullptr;
    }
    void game_init() {
        printf("[%s] 로드된 게임의 초기화 함수 호출 \n", cabinet_model_str);
        if (installed_game) {
            installed_game->game_init();
        }
        else {
            printf("장착된 게임이 없습니다.\n");
        }
    }
    void game_start() {
        if (installed_game) {
            installed_game->game_start();

            is_running = true;
            while (is_running) {
                int key = _getch(); // Windows에서는 _getch()
                installed_game->key_input(key);
                printf("[%s] 캐비닛이 입력받은 키 값: %d\n", cabinet_model_str, key);
                if (key == 'q') is_running = false;
            }
        }
        else {
            printf("장착된 게임이 없습니다.\n");
        }
    }
};
*/

#include <cstdio>
#include <conio.h>
#include "Cabinet.h"

void Cabinet::hw_check() {
	printf("[%s] Cabinet 전원 체크, 롬 체크 등\n", cabinet_model_str);
}

void Cabinet::load_game(IGame* game) {
    installed_game = game;
}

void Cabinet::unload_game() {
    delete installed_game;
    installed_game = nullptr;
}

void Cabinet::game_init() {
    printf("[%s] 로드된 게임의 초기화 함수 호출 \n", cabinet_model_str);
    if (installed_game) {
        installed_game->game_init();
    }
    else {
        printf("장착된 게임이 없습니다.\n");
    }
}

void Cabinet::game_start() {
    if (installed_game) {
        installed_game->game_start();
        is_running = true;
        while (is_running) {
            int key = _getch();
            installed_game->key_input(key);
            printf("[%s] 캐비닛이 입력받은 키 값: %d\n", cabinet_model_str, key);
            if (key == 'q') is_running = false;
        }
    }
    else {
        printf("장착된 게임이 없습니다.\n");
    }
}


void Cabinet::intro(int init_coins) {
    std::cout << "============================================\n";
    std::cout << "  1조 게임기를 즐기러 오신 당신을 환영합니다!\n";
    std::cout << "============================================\n";
    std::cout << "\n";
	std::cout << "코인 추가: c" << "\n";
    std::cout << "게임 선택: p" << "\n";

    while (true) {
        if (_kbhit()) {
			char key = _getch();
			if (key == 'c' || key == 'C') {
                std::cout << "현재 코인 갯수: " << this->coin << "\n";
                continue;
			}
			else if (key == 'p' || key == 'P') {
                break;
			}
			else {
				std::cout << "잘못된 입력입니다.\n";
			}
        }
    }
}