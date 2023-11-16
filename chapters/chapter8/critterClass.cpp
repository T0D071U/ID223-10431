// Critter CareTaker

#include <iostream>
using namespace std;

class Critter {
    public:
    string m_Name;

    Critter(string m_Name = "Critter");
    void TimePassed();
    string GetHunger();
    string GetBoredom();
    string Mood(int random);

    private:
    int m_Hunger{10};
    int m_Boredom{10};
};

void Critter::TimePassed(){
    m_Hunger -= 3;
}

Critter::Critter(string name){
    m_Name = name;
}

string Critter::GetHunger() {
    return m_Name + " current hunger levels are: " + to_string(m_Hunger) + '\n';
}

string Critter::GetBoredom() {
    return m_Name + " current boredom levels are: " + to_string(m_Boredom) + '\n';
}
