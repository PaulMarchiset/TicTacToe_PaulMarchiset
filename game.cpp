// #include "game.hpp"

// std::array<char, 9> gameboard{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// void draw_game_board()
// {
//     for (int i = 0; i < gameboard.size(); i++)
//     {
//         if (i % 3 == 0)
//         {
//             std::cout << "| ";
//             std::cout << static_cast<char>(gameboard[i]) << " | ";
//             std::cout << gameboard[i] << " | ";
//             if ((i + 1) % 3 == 0)
//             {
//                 std::cout << std::endl;
//             }
//         }
//     }
// }

// void gameplay(Player &player)
// {
//     int choice;
//     std::cout << player.name << " choisissez une case" << std::endl;
//     std::cin >> choice;

//     if (gameboard[choice - 1] == 'X' || gameboard[choice - 1] == 'O')
//     {
//         std::cout << "Case déjà prise" << std::endl;
//         gameplay(player);
//     }
//     else
//     {
//         gameboard[choice - 1] = player.symbol;
//     }

//     draw_game_board();
// }
