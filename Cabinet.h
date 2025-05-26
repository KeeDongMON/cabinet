// Cabinet.h
/*
#pragma once
#include "IGame.h"

class Cabinet : public IGame {
    const char* cabinet_model_str = "캐비닛 R100";
    IGame* installed_game = nullptr;
    bool is_running = false;

public:
    Cabinet();
    Cabinet(IGame* game);
    Cabinet(const Cabinet&) = delete;
    Cabinet& operator=(const Cabinet&) = delete;

    void hw_check();
    void load_game(IGame* game);
    void unload_game();

    void game_init() override;
    void game_start() override;
    void game_over() override;
    void send_key_input(int key_code);
};
*/

#pragma once
#include "IGame.h"
#include "RockPaperScissors.h"
#include <vector>
<<<<<<< Updated upstream
=======
#include <Windows.h>
#include "RockPaperScissors.h" // 예시 게임 클래스
>>>>>>> Stashed changes

class Cabinet {
    const char* cabinet_model_str = "캐비닛 R123";
    IGame* installed_game = nullptr;
	std::vector<IGame*> games; // 게임 목록
    bool is_running = false;
    int coin = 0;
<<<<<<< Updated upstream

public:
    Cabinet() {
		IGame* demo_game = new RockPaperScissors();
        IGame* demo_game_2 = new RockPaperScissors();
        games.push_back(demo_game);
		games.push_back(demo_game_2);
    }
=======
    //bool power_on = true; // 전원 상태

public:
	Cabinet();
>>>>>>> Stashed changes
    void hw_check();
    void load_game(IGame* game);
    void unload_game();
    void game_init();
    void game_start();
	void intro(int init_coins);
	void clearScreen();
	void getGame();
    bool offCheck();
};