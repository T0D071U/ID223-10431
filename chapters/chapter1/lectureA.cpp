// Timothy Deahl ID223
// Fall 2023

#include <iostream>

int main(){
    std::cout << "Game over!\n"; //presuming the game is already over
    std::cout << "Would you like to play again?\n";
    std::cout << "Enter 1 for yes, or 2 for no: ";

    int playAgain;
    std::cin >> playAgain; // Gets user input and stores it in playAgain

    if (playAgain == 1){
        std::cout << "Let's play again!\n";
    } else {
        std::cout << "Aw! See you later!\n";
    }

    return 0;
}