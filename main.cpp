#include "graphics.h"

int main()
{
    std::string input;
    std::cout << "Welcome to swift!\n";

    graphics_init();
    // while (getline(std::cin, input) && input != "quit")
    // {
    //     std::cout << "I hear you say " << input << " but it doesn't do anything yet. Try 'start' to open a window with the game!\n";
    // }

    std::cout << "Game will close.\n"; // switch to x11 omigosh
    return 0;
}