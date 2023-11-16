// practice yum
#include <iostream>
#include <string>

int main(){
    int* pAPointer; //declare a pointer
    int* pScore = 0; //Declare and initalize a pointer

    int score = 1000;

    pScore = &score; //assign pointer pScore address of var score

    std::cout << "Assigning &score to pScorer\n";
    std::cout << "&score is: " << &score << "\n";
    std::cout << "pScore is: " << pScore << '\n';
    std::cout << "score is: " << score << '\n';
    std::cout << "*pScore is :" << *pScore << "\n\n";

    std::cout << "Adding 500 to score\n";
    score += 500;
    std::cout << "score is: " << score << '\n';
    std::cout << "pScore is: " << pScore << '\n';
    std::cout << "*pScore is :" << *pScore << "\n\n";

    std::cout << "Assigning &newScore to pScore\n";
    int newScore{5000};
    pScore = &newScore;
    std::cout << "&newScore is: " << &newScore << '\n';
    std::cout << "pScore is: " << pScore << '\n';
    std::cout << "newScore is: " << newScore << '\n';
    std::cout << "*pScore is: " << *pScore << "\n\n";
    
    std::cout << "Assigning &str to pStr\n";
    std::string str{"score"};
    std::string* pStr{&str};

    std::cout << "str is: " << str << '\n';
    std::cout << "*pStr is: " << *pStr << '\n';
    std::cout << "(*pStr).size() is: " << (*pStr).size() << '\n';
    std::cout << "pStr->size() is: " << pStr->size() << '\n';


    return 0;
}