#include "player.hpp"

Player create_player()
{
   Player player;
   std::cout << "Votre nom" << std::endl;
   std::cin >> player.name;
   std::cout << "Votre symbole" << std::endl;
   std::cin >> player.symbol;

   return player;
}

Player create_AI()
{
   Player player;
   player.name = "AI";
   player.symbol = '*';
   return player;
}