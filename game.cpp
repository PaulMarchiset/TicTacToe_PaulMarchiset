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
    draw_game_board();
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
    }
}

void gameplayAIEasy(Player &player)
{
    int choice{0};
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
    int choice{0};

    std::cout << player.name << " is playing..." << std::endl;
    draw_game_board();

    for (int i{0}; i < 9; i++)
    {
        if (isPlayable(i + 1))
        {
            char backup{gameboard[i]};
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
        for (int i{0}; i < 9; i++)
        {

            if (i + 7 < 9 && !isPlayable(i + 1) && !isPlayable(i + 4))
            {
                if (isPlayable(i + 7))
                {
                    choice = i + 7;
                }
            }
            if (i + 4 < 9 && !isPlayable(i + 1) && !isPlayable(i + 7))
            {
                 if (isPlayable(i + 4))
                {
                    choice = i + 4;
                }
            }
            if (i * 3 + 3 < 9 && !isPlayable(i * 3 + 1) && !isPlayable(i * 3 + 2))
            {
                if (isPlayable(i * 3 + 3))
                {
                    choice = i * 3 + 3;
                }
            }
            if (i * 3 + 2 < 9 && !isPlayable(i * 3 + 1) && !isPlayable(i * 3 + 3))
            {
                if (isPlayable(i * 3 + 2))
                {
                    choice = i * 3 + 2;
                }
            }
            if (choice != 0)
                break;
        }
    }

    if (choice == 0 && isPlayable(5))
    {
        choice = 5;
    }

    if (choice == 0)
    {
        int corners[] = {1, 3, 7, 9};
        do
        {
            choice = corners[rand() % 4];
        } while (!isPlayable(choice));
    }

    if (choice == 0)
    {
        do
        {
            choice = rand() % 9 + 1;
        } while (!isPlayable(choice));
    }

    std::cout << player.name << " choice : " << choice << std::endl;
    gameboard[choice - 1] = player.symbol;
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
    int aiDifficulty{0};
    if (game_AI)
    {
        std::cout << "Choose the AI difficulty : easy (0) and hard (1)" << std::endl;
        std::cin >> aiDifficulty;
    }

    // int random_start{rand() % 2};
    int random_start{2};

    for (int i{random_start}; i < random_start + 9; i++)
    {
        if (i % 2 == 0)
        {
            if (gameWin(player2) == true)
            {
                std::cout << player2.name << " win :)" << std::endl;
                draw_game_board();
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
                draw_game_board();
                break;
            }
            else
            {
                if (game_AI)
                {
                    if (aiDifficulty == 0)
                    {
                        gameplayAIEasy(player2);
                    }
                    else
                    {
                        gameplayAIHard(player2);
                    }
                }
                else
                {
                    gameplay(player2);
                }
            }
        }
    }
    if (!gameWin(player1) && !gameWin(player2))
    {
        draw_game_board();
        std::cout << "The game is a draw :(" << std::endl;
    }
}