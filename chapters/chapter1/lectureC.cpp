// Timothy Deahl ID223
// Fall 2023
// Chapter 1c programmer math operators, enums, and constants

#include <iostream>

int main(){
    std::cout << "Changing variables!\n";

    int totalPuppies = 9;

    std::cout << "We have " << totalPuppies << " puppies!\n";
    std::cout << "we have some friends who want to take a puppy home.\n";
    totalPuppies = 8;        // Do the math in our heads, assign a new value.

    std::cout << "We have " << totalPuppies << " puppies!\n";
    std::cout << "We have some friends who want to take a puppy home.\n";
    totalPuppies = totalPuppies - 1;

    std::cout << "We have " << totalPuppies << " puppies!\n";
    std::cout << "Our friends what to take home two puppies!\n";
    totalPuppies -= 2;

    std::cout << "We have " << totalPuppies << " puppies!\n";
    // Increment and decrement operators.
    std::cout << "We miscounted our puppies and found another one!\n";
    totalPuppies++;

    std::cout << "We have " << totalPuppies << " puppies!\n";
    std::cout << "We give away another pup.\n";
    totalPuppies--;

    std::cout << "We have " << totalPuppies << " puppies!\n";
    std::cout << '\n';

    //Constants
    std::cout << "Let's talk about Enumerators and Constants!\n";

    const float gravityForce = -9.81f;      //This can not change

    const std::string playerName = "Luke";

    //Enums are a simple variable type with limited programmer defined types
    enum directions {NORTH, EAST, SOUTH, WEST};
    directions playerDirection = NORTH;
    
    enum difficulty {EASY=1, NORMAL, HARD};
    enum difficulty playerDifficulty = NORMAL;

    std::cout << "You meet a Goblin!\n";
    std::cout << "The Goblin's damage is " << 5 * playerDifficulty << ".\n";

    return 0;   
}