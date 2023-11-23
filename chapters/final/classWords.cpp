#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {SPORTSHOP, CASINO, CARPARK, LOBBY, RESTAURANT, CORRIDOR, STOREROOM,
                POOL, GARDEN, POND, PUMPROOM};
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, EQUIP, ATTACK};
enum en_NOUNS {STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 11;
const int VERBS = 10;
const int NOUNS = 6;


class Words {
    public:
        Words(string word="", int code=0) {
            m_Word = word;
            m_Code = code;
        }

        string getWord() const {return m_Word;}
        int getCode() const {return m_Code;}

    private:
        string m_Word;
        int m_Code;
};

void set_directions (vector<Words> *dir) {
    dir->push_back(Words("NORTH", NORTH));
    dir->push_back(Words("EAST", EAST));
    dir->push_back(Words("SOUTH", SOUTH));
    dir->push_back(Words("WEST", WEST));
}

void set_verbs (vector<Words> *vbs) {
    vbs->push_back(Words("GET", GET));
    vbs->push_back(Words("DROP", DROP));
    vbs->push_back(Words("USE", USE));
    vbs->push_back(Words("OPEN", OPEN));
    vbs->push_back(Words("CLOSE", CLOSE));
    vbs->push_back(Words("EXAMINE", EXAMINE));
    vbs->push_back(Words("INVENTORY", INVENTORY));
    vbs->push_back(Words("LOOK", LOOK));
    vbs->push_back(Words("EQUIP", EQUIP));
    vbs->push_back(Words("ATTACK", ATTACK));
}

int main() {
    string command;
    string word_1;
    string word_2;

    vector<Words> Directions;
    set_directions(&Directions);

    vector<Words> Verbs;
    set_verbs(&Verbs);



    for(int i = 0; i < VERBS; i++) {
        cout << Verbs[i].getWord() << endl;
    }
}