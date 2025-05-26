#include <iostream>
#include <conio.h> // Windows 환경에서 _getch() 사용

#include <cstdio>
#include "Cabinet.h"


// 4. 실행 예시
//#include "Cabinet.h"
//#include "RockPaperScissors.h"

int main() {
    Cabinet cabinet;
    cabinet.hw_check();

    //초기화면
    while (cabinet.offCheck()) {
        cabinet.intro(0); // 코인갯수 0
        cabinet.clearScreen();
        //코인인풋
        //cabinet.coin_input();
        
        //게임선택
        //cabinet.getGame(); //    RockPaperScissors* game = new RockPaperScissors();  //TicTacToe* game = new TicTacToe();
        cabinet.load_game(); // cabinet.load_game(game);
        //게임실행
        cabinet.game_init();
        cabinet.game_start();
        cabinet.unload_game();
        //게임오버로 초기화면으로 복귀
        //전원끌지 안끌지 체크
        //Cabinet cabinet;

        //cabinet.load_game(ttt_game);
    }


    return 0;
}