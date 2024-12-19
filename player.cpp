#include "player.hpp"

Player create_player()
{
   Player player;
   std::cout << "Your name" << std::endl;
   std::cin >> player.name;
   std::cout << "Your symbol" << std::endl;
   std::cin >> player.symbol;
   if (player.symbol >= 1 && player.symbol <= 9) {
      std::cout << "Your symbol can't be a numeral value other than 0" << std::endl;
      std::cin >> player.symbol;
   }

   return player;
}

Player create_AI()
{
   Player player;
   player.name = "AI";
   player.symbol = '*';
   return player;
}