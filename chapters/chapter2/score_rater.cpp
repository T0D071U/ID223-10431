// Timothy Deahl, ID223, Fall 2023
// Score Rater -> Demostrates the if statement

#include <iostream>

int main(){
    if(true){
        std::cout << "This is always displayed.\n\n";
    }

    if(false){
        std::cout << "This is never shown since it is false!\n\n";
    }

    int score = 1000;

    if(score){
        std::cout << "Atleast you did not score zero!\n\n";
    }

    if(score >= 250){
        std::cout << "You scored 250 or more. Decent.\n\n";
    }

    if (score >= 500) {
        std::cout << "You scored 500 or more. Nice.\n\n";

        if (score >= 1000){
            std::cout << "You scored 1000 or more. Impressive!\n\n";
        }
    }


    return 0;
}