// Timothy Deahl ID223
// Fall 2023

#include <iostream>

int main(){
    //Starting with numbers
    std::cout << "All about numbers!\n";

    std::cout << "2 + 2 = " << 2+2 << std::endl;
    std::cout << "10 - 5 = " << 10-5 << std::endl;
    std::cout << "3 * 3 = " << 3*3 << std::endl;
    std::cout << "7 / 2 = " << 7/2 << std::endl;
    std::cout << "7.0 / 2.0 = " << 7.0/2.0 << std::endl;

    //modulus opperator
    std::cout << "The remainder of 7 / 2 is: " << 7%2 << std::endl;

    std::cout << "15 / 6 = " << 15/6 << ", ";
    std::cout << "r= " << 15%6 << std::endl;

    // order of operations
    std::cout << "7 * 3 + 5 = " << 7*3+5 << std::endl; 
    std::cout << "7 * (3+5) = " << 7*(3+5) << std::endl;

    // VARIABLES
    std::cout << '\n';
    std::cout << "Lets talk about variables!\n"; 

    int age = 18;                   // int named age
    std::string name = "Timothy";   // String named name

    std::cout << "\nHello, my name is " << name << ".\n";
    std::cout << "I am " << age << " years old!\n";

    std::cout << "What is your characters name? ";

    std::string charName; // A string with no value
    std::cin >> charName; // Assigns the player input

    std::cout << "Hello " << charName << "! It's nice to meet you.\n";

    //Numbers
    int playerLives = 3;        // Whole numbers
    float playerSpeed = 42.7f;  // Decimal numbers with 7 digit's of accuracy
    double pi = 3.1415;         // Decimal numbers with 22 digit's of accuracy
    // Characters

    char yes = 'y';     //single character, use single quotes
    char initial = 'b';

    std::string phrase = "Strings can be as long as you want!";

    bool playerIsAlive = 1;     // Can either be 1 or 0 / true or false

    
    return 0;
}