#pragma once

#include <iostream>
#include <string>
#include <array>
#include <vector>

struct Player
{
   std::string name;
   char symbol;
};

Player create_player();

Player create_AI();
