// Cabinet.h
/*
#pragma once
#include "IGame.h"

class Cabinet : public IGame {
    const char* cabinet_model_str = "Ä³ºñ´Ö R100";
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

class Cabinet {
    const char* cabinet_model_str = "Ä³ºñ´Ö R123";
    IGame* installed_game = nullptr;
	std::vector<IGame*> games; // °ÔÀÓ ¸ñ·Ï
    bool is_running = false;
    int coin = 0;

public:
    Cabinet() {
		IGame* demo_game = new RockPaperScissors();
        IGame* demo_game_2 = new RockPaperScissors();
        games.push_back(demo_game);
		games.push_back(demo_game_2);
    }
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