#include "graphics.h"

int main()
{
    std::string input;
    std::cout << "Welcome to swift!\n";

    while (getline(std::cin, input) && input != "quit")
    {
        std::cout << "I hear you say " << input << " but it doesn't do anything yet.\n";
    }

    std::cout << "Game will close.\n";
    return 0;
}