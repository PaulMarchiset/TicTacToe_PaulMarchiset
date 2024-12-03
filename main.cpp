#include "main.hpp"

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

bool isPlayable(int &choice)
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

void gameplayAI(Player &player)
{
    srand(time(NULL));

    int choice{rand() % 9 + 1};

    if (whoFirst() == true)
    {
        std::cout << player.name << " your turn to play" << std::endl;
        int corners[] = {1, 3, 7, 9};
        choice = corners[rand() % 4];
        gameboard[choice - 1] = player.symbol;
        draw_game_board();
    }
    else if (gameboard[4] >= '1' && gameboard[4] <= '9')
    {
        gameboard[4] = player.symbol;
        draw_game_board();
    }
    else if (gameboard[4] == player.symbol && (gameboard[0||2||6||8] == player.symbol))
    {
        int corners[] = {1, 3, 7, 9};
        choice = corners[rand() % 4];
        if (isPlayable(choice) == false)
        {
            gameplayAI(player);
        }
        else
        {
            gameboard[choice - 1] = player.symbol;
            draw_game_board();
        }
    }
    else
    {
        std::cout << player.name << " your turn to play" << std::endl;
        if (isPlayable(choice) == false)
        {
            gameplayAI(player);
        }
        else
        {
            gameboard[choice - 1] = player.symbol;
            draw_game_board();
        }
    }
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
            else
            {
                return false;
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
                    gameplayAI(player2);
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

int main()
{
    srand(time(NULL));

    bool choice{false};

    std::cout << "SoloQ vs IA (0) or 2 players (1) ?" << std::endl;
    std::cin >> choice;

    if (choice == false)
    {
        game_AI();
    }
    else
    {
        game_duo();
    }
    return 0;
}