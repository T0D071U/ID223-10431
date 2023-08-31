// Timothy Deahl, ID223, Fall 2023
// Trying to recreate the play again program before looking at the solution, it uses while loops.

#include <iostream>

int main() {
    // defining of variables.
    char keepPlaying = 'y';

    // start of while loop
    while (keepPlaying == 'y') {
        std::cout << "** Played and exciting game! **\n";
        std::cout << "Would you like to play again? (y/n): ";

        std::cin >> keepPlaying;

        std::cout << '\n';
    }

    std::cout << "Okay, Bye!\n";

    return 0;
}