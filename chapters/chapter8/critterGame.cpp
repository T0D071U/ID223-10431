// Critter CareTaker
#include <iostream>

using namespace std;

class Critter{};


int main (){
    Critter crit;
    crit.m_Name = "Tomas";
    cout << crit.Mood(1);
    cout << crit.GetHunger();
    cout << crit.GetBoredom();

    return 0;
}