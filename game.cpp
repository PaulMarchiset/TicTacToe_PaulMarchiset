#include "game.hpp"

void whoPlay(Player &player1, Player &player2);

void game_AI()
{
    Player player1{create_player()};
    Player player2{create_AI()};
    whoPlay(player1, player2);
}

void game_duo()
{
    Player player1{create_player()};
    Player player2{create_player()};
    whoPlay(player1, player2);
}

std::array<char, 9> gameboard{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw_game_board()
{
    for (int i = 0; i < gameboard.size(); i++)
    {
        if (i % 3 == 0)
        {
            std::cout << "| ";
        }

        std::cout << gameboard[i] << " | ";

        if ((i + 1) % 3 == 0)
        {
            std::cout << std::endl;
        }
    }
}

bool isPlayable(const int &choice)
{
    if (gameboard[choice - 1] >= '1' && gameboard[choice - 1] <= '9')
    {
        return true;
    }
    return false;
}

void gameplay(Player &player)
{
    int choice{0};
    std::cout << player.name << " your turn to play" << std::endl;
    std::cin >> choice;
    if (isPlayable(choice) == false)
    {
        std::cout << "You can't play here" << std::endl;
        gameplay(player);
        std::cout << std::endl;
    }
    else
    {
        std::cout << player.name << std::endl;
        gameboard[choice - 1] = player.symbol;
        draw_game_board();
    }
}

bool whoFirst()
{
    std::array<char, 9> gameboardTest{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    if (gameboardTest == gameboard)
    {
        return true;
    }
    return false;
}

void gameplayAIEasy(Player &player)
{
    int choice {5};
    std::cout << player.name << " is playing..." << std::endl;

        do
        {
            choice = rand() % 9 + 1;
        } while (!isPlayable(choice));
    
    gameboard[choice - 1] = player.symbol;
    draw_game_board();
}

void gameplayAIHard(Player &player)
{
    int choice {0};

    std::cout << player.name << " is playing..." << std::endl;

    for (int i = 0; i < 9; i++)
    {
        if (isPlayable(i + 1))
        {
            char backup {gameboard[i]};
            gameboard[i] = player.symbol; 
            if (gameWin(player))
            {
                choice = i + 1;
            }
            gameboard[i] = backup; 
            if (choice != 0)
                break;
        }
    }

    if (choice == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            if (isPlayable(i + 1))
            {
                char backup = gameboard[i];
                gameboard[i] = '*'; 
                if (gameWin(player)) 
                {
                    choice = i + 1;
                }
                gameboard[i] = backup; 
                if (choice != 0)
                    break;
            }
        }
    }

    if (choice == 0 && isPlayable(5))
    {
        choice = 5;
    }

    if (choice == 0)
    {
        int corners[] = {1, 3, 7, 9};
        for (int oneCorner : corners)
        {
            if (isPlayable(oneCorner))
            {
                choice = oneCorner;
                break;
            }
        }
    }

    if (choice == 0) 
    {
        do
        {
            choice = rand() % 9 + 1;
        } while (!isPlayable(choice));
    }

    gameboard[choice - 1] = player.symbol;
    draw_game_board();
}


bool gameWin(Player &player)
{
    if (gameboard[4] == player.symbol && ((gameboard[0] == player.symbol && gameboard[8] == player.symbol) || (gameboard[2] == player.symbol && gameboard[6] == player.symbol)))
    {
        return true;
    }
    else
    {
        for (int i{0}; i < 3; i++)
        {
            if (gameboard[i] == player.symbol && gameboard[i + 3] == player.symbol && gameboard[i + 6] == player.symbol)
            {
                return true;
            }
            else if (gameboard[i * 3] == player.symbol && gameboard[i * 3 + 1] == player.symbol && gameboard[i * 3 + 2] == player.symbol)
            {
                return true;
            }
        }
    }
    return false;
}

void whoPlay(Player &player1, Player &player2)
{
    draw_game_board();
    int random_start{rand() % 2};
    for (int i{random_start}; i < random_start + 9; i++)
    {
        if (i % 2 == 0)
        {
            if (gameWin(player2) == true)
            {
                std::cout << player2.name << " win :)" << std::endl;
                break;
            }
            else
            {
                gameplay(player1);
            }
        }
        else
        {
            if (gameWin(player1) == true)
            {
                std::cout << player1.name << " win :)" << std::endl;
                break;
            }
            else
            {
                if (player2.name == "AI")
                {
                    gameplayAIHard(player2);
                }
                else
                {
                    gameplay(player2);
                }
            }
        }
    }
    if (gameWin(player1) == false && gameWin(player2) == false)
    {
        std::cout << "Draw :(" << std::endl;
    }
}