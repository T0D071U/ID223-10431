// simple criter
#include <iostream>

using namespace std;

class Critter 
{
    public:
        int m_Hunger;
        Critter(int hunger = 0);
        void Greet();
};

Critter::Critter(int hunger){
    cout << "A new critter has been born!" << endl;
    m_Hunger = hunger;
}

void Critter::Greet(){
    cout << "Hi, i'm a critter. My hunger level is " << m_Hunger << "\n";
}

int main () {
    Critter crit1(7);
    crit1.Greet();
    return 0;
}