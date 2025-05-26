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
#include <cstdint>
#include <vector>
#include <Windows.h>

class Cabinet {
    const char* cabinet_model_str = "Ä³ºñ´Ö R123";
    IGame* installed_game = nullptr;
    std::vector<IGame*> games;
    bool is_running = false;
    //bool power_on = true; // Àü¿ø »óÅÂ

public:
    void hw_check();
    void load_game(IGame* game);
    void load_game();
    void unload_game();
    void game_init();
    void game_start();
    bool offCheck();
    //void init();
    void intro(int init_coins);
    void coin_input();
    void clearScreen();
    void getGame();
};



