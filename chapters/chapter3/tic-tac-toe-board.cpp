//Timothy Deahl, ID223
//Trying to make a tic-tac-toe board using arrays!

#include <iostream>

int main(){
    // print here is the tictactoe board
    std::cout << "Here's the tic-tac-toe board!\n";

    //make the array and print the board
    const int ROWS = 3; 
    const int COLUMNS = 3;
    char Board[ROWS][COLUMNS] = {{'X', 'O', 'O'},
                                 {' ', 'O', 'X'}, 
                                 {'X', 'X', 'O'}};
    
    for(int y=0; y < ROWS; y++){
        for(int x=0; x<COLUMNS; x++){
            std::cout << Board[y][x];
        }
        std::cout << '\n';
    }

    //print x moves to the empty location
    std::cout << "\nX moves to the empty spot!\n";

    Board[1][0] = 'X';

    //print new board
    for(int y=0; y < ROWS; y++){
        for(int x=0; x<COLUMNS; x++){
            std::cout << Board[y][x];
        }
        std::cout << '\n';
    }

    //print x wins
    std::cout << "\nCongrats!! X wins!\n";

    return 0;
}