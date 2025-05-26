#include <cstdio>
#include <conio.h> // Windows 환경에서 _getch() 사용
#include "Cabinet.h"
#include <iostream>
#include "key.h"

// 3. 캐비닛 클래스 구현    

//class Cabinet {
//    const char* cabinet_model_str = "캐비닛 R123";
//    IGame* installed_game = nullptr;
//    bool is_running = false;
//public:
//    void hw_check() {
//        printf("[%s] Cabinet 전원 체크, 롬 체크 등\n", cabinet_model_str);
//    }
//    void load_game(IGame* game) {
//        installed_game = game;
//    }
//    void unload_game() {
//        delete installed_game;
//        installed_game = nullptr;
//    }
//    void game_init() {
//        printf("[%s] 로드된 게임의 초기화 함수 호출 \n", cabinet_model_str);
//        if (installed_game) {
//            installed_game->game_init();
//        }
//        else {
//            printf("장착된 게임이 없습니다.\n");
//        }
//    }
//    void game_start() {
//        if (installed_game) {
//            installed_game->game_start();
//
//            is_running = true;
//            while (is_running) {
//                int key = _getch(); // Windows에서는 _getch()
//                installed_game->key_input(key);
//                printf("[%s] 캐비닛이 입력받은 키 값: %d\n", cabinet_model_str, key);
//                if (key == 'q') is_running = false;
//            }
//        }
//        else {
//            printf("장착된 게임이 없습니다.\n");
//        }
//    }
//};


//#include <cstdio>
//#include <conio.h> // Windows 환경에서 _getch() 사용
//#include "Cabinet.h"

void Cabinet::hw_check() {
    printf("[%s] Cabinet 전원 체크, 롬 체크 등\n", cabinet_model_str);
}



void Cabinet::load_game() {
    int idx = 0;
    std::cout << "게임 선택. 방향키로 게임을 골라보세요. \n";
    while (true) {
        int key = (get_key_code());
        if (key == KEY_ENTER) //ENTER
            break;
        else if (key == KEY_LEFT || key == KEY_DOWN) {
            idx = (idx == 0) ? 2 : idx - 1; //게임목록 2일떄
        }
        else if (key == KEY_UP || key == KEY_RIGHT) {
            //idx++;
            idx = (idx == 2 - 1) ? 0 : idx + 1;
        }
        std::cout << "[%d]번 게임 선택하시겠습니까? 선택하려면 ENTER를 누르세요. \n";
    }

    IGame* selectedGame = games[idx];
    installed_game = selectedGame;

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

bool Cabinet::offCheck() {
    std::cout << "ESC를 눌러 캐비닛 전원을 끄거나 다른 키를 눌러 초기화면으로 돌아갑니다.\n";
    int key = _getch();

    if (key == (0x1B)) {
        std::cout << "캐비닛 전원이 꺼졌습니다.\n";
        return false; // 전원 끄기
    }
    else {
        std::cout << "초기화면으로 돌아갑니다.\n";
        return true; // 초기화면으로 돌아가기
    }

}
void Cabinet::intro(int init_coins) {
    std::cout << "============================================\n";
    std::cout << "  1조 게임기를 즐기러 오신 당신을 환영합니다!\n";
    std::cout << "============================================\n";
    std::cout << "\n";
    std::cout << "현재 코인 갯수: " << init_coins << "\n";
}

void Cabinet::clearScreen() {
    Sleep(10);
    printf("\033[2J\033[H"); // ANSI Escape Code로 화면 지우기

}