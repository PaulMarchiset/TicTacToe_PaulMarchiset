#pragma once

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "player.hpp"

void whoPlay(Player &player1, Player &player2);
void game_AI();
void game_duo();
void draw_game_board();
bool isPlayable(const int &choice);
void gameplay(Player &player);
void gameplayAIEasy(Player &player);
void gameplayAIHard(Player &player);
bool gameWin(Player &player);