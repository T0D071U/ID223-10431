// Critter farm
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Critter {
    public:
        Critter(const string& name = "");
        string GetName() const;

    private:
        string m_Name;
};

Critter::Critter(const string& name){
    m_Name = name;
}

inline string Critter::GetName() const {
    return m_Name;
}

class Farm {
    public:
        Farm(int spaces =1);
        void Add(const Critter& aCritter);
        void RollCall() const;
    
    private:
        vector<Critter> m_Critters;
};

Farm::Farm(int spaces){
    m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter){
    m_Critters.push_back(aCritter);
}

void Farm::RollCall() const {
    for (vector<Critter>::const_iterator iter = m_Critters.begin(); 
    iter != m_Critters.end(); ++iter){
        cout << iter->GetName() << " here.\n";
    }
}

int main(){
    Critter crit("Poochie");
    cout << crit.GetName() << "\n";

    Farm myFarm(3);

    myFarm.Add(Critter("moe"));
    myFarm.Add(Critter("meoe"));
    myFarm.Add(Critter("meeoe"));
    myFarm.Add(crit);

    myFarm.RollCall();


    return 0;
}