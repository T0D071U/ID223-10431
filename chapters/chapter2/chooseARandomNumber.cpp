// Timothy Deahl, ID223 2023
// Guess a random number between 1-100!

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(time(0));
    const int randNumber((std::rand() % 100)+1);

    int playerGuess(0);

    while(playerGuess != randNumber){
        std::cout << "Guess the number: ";

        std::cin >> playerGuess;

        if (playerGuess > randNumber){
            std::cout << "Try to guess lower!\n\n";
        } else if (playerGuess < randNumber){
            std::cout << "Try to guess higher!\n\n";
        }
    }

    std::cout << "Good job! The random number was " << randNumber << "!\n";
    return 0;
}

