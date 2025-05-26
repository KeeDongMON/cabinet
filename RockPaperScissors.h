#pragma once
#include "IGame.h"

class RockPaperScissors : public IGame {
    const char* game_title_str = "가위바위보 ";
public:
    void game_init() override;
    void game_start() override;
    void game_over() override;
    void key_input(int key_code) override;
};