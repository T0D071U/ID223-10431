// Timothy Deahl, ID223, Fall 2023
// I tried making this on my own before seeing what the textbook said about it.

#include <iostream>

int main() {
    //Starts with showing the gui
    std::cout << "Difficulty levels:\n\n";

    std::cout << "  1 - Easy\n";
    std::cout << "  2 - Normal\n";
    std::cout << "  3 - Hard\n\n";

    std::cout << "Make your choice: ";

    // Gets user input
    int difficultyInput;
    std::cin >> difficultyInput;

    //Tests that user input against a switch list
    switch (difficultyInput){
        case 1:
            std::cout << "You chose option 1 - Easy!\n\n";
            break;
        case 2:
            std::cout << "You chose option 2 - Normal!\n\n";
            break;
        case 3:
            std::cout << "You chose option 3 - Hard!\n\n";
            break;
        default:
            std::cout << "Invalid Option\n\n";
    }

    //ends
    return 0;
}