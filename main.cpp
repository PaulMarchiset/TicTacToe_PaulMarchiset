#include "main.hpp"

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