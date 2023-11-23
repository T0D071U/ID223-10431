#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {GARDEN, STUDY, WELLROOM, KITCHEN, LIBRARY, GSBEDROOM, PATH, 
                DINING_ROOM, FAMILY_ROOM, MBATHROOM, HALLWAY, HALLWAY2, 
                ENTRANCE, FOYER, MBEDROOM, VAULT, POND, GUARDROOM, 
                SHALLWAY, SQUARTERS, LAUNDRY, STORAGE};
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};
enum en_NOUNS {WELL, MANSION_KEY, FLOWERS, FOUNTAIN, SWORD, 
                FOOD, SERVANT_KEY, CHESTPLATE, CLOTHES, BARRELS, CRATES, 
                BEDROOM_KEY, STUDY_KEY, NOTEBOOK, COINS};
enum en_DOORS {MANSION_DOOR, SERVANT_DOOR, BEDROOM_DOOR, STUDY_DOOR, VAULT_DOOR};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 11;
const int VERBS = 8;
const int NOUNS = 15;
const int DOORS = 5;

class Rooms {
    public:
        Rooms(string description = "", int north = NONE, int east = NONE, int south = NONE, int west = NONE) {
            m_Description = description;

            m_Exits[NORTH] = north;
            m_Exits[EAST] = east;
            m_Exits[SOUTH] = south;
            m_Exits[WEST] = west;
        }
        string getDesc() const {return m_Description;}
        int getExits(int dir){return m_Exits[dir];}
        void setExits (int fromDir, int toDir) {
            m_Exits[fromDir] = toDir;
        }

    private:
        string m_Description;
        int m_Exits[DIRS];
};

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

class Nouns {
    public:
        Nouns(string word = "", int code = NONE, string description = "", int location = NONE, bool canCarry = false){
            m_Word = word;
            m_Code = code;
            m_Description = description;
            m_Location = location;
            m_CanCarry = canCarry;
        }

        string getWord(){return m_Word;}
        int getCode(){return m_Code;}
        string getDesc(){return m_Description;}

        void setDesc(string value){
            m_Description.clear();
            m_Description.assign(value);
        }

        int getLocation(){return m_Location;}
        void setLocation(int location) {m_Location = location;}
        bool ifCarry(){return m_CanCarry;}

    private:
        string m_Word;
        int m_Code;
        string m_Description;
        int m_Location;
        bool m_CanCarry;
};

class Doors {
    public:
        Doors(string word = "", int code = NONE, string description = "", int exit1 = NONE, int exit2 = NONE, int direction = NONE, bool isLocked = false, int key = NONE){
            m_Word = word;
            m_Code = code;
            m_Description = description;

            m_Exit1 = exit1; //first room
            m_Exit2 = exit2; // the room the door leads to
            
            m_Dir1 = direction; // direction the door leads to
            if(m_Dir1 == NORTH){m_Dir2 = SOUTH;} // direction the otherside leads too
            if(m_Dir1 == SOUTH){m_Dir2 = NORTH;}
            if(m_Dir1 == EAST){m_Dir2 = WEST;}
            if(m_Dir1 == WEST){m_Dir2 = EAST;}

            m_IsLocked = isLocked;
            m_Key = key;

            m_IsOpened = false;   
        }

        void open(int loc, vector<Rooms> *rms);

        string getWord(){return m_Word;}
        int getCode(){return m_Code;}
        string getDesc(){
            if(m_IsOpened == true){
                return "a opened " + m_Description;
            } else if (m_IsOpened == false && m_IsLocked == false) {
                return "a closed " + m_Description;
            } else if (m_IsLocked == true){
                return "a locked " + m_Description;
            }
            return "THERE IS AN ERROR!!! IN DOORS GET DESC";
        }

        void setDesc(string value){
            m_Description.clear();
            m_Description.assign(value);
        }

        int getExits(int value) {
            if(value == 0){
                return m_Exit1;
            } else {
                return m_Exit2;
            }
        }

    private:
        string m_Word;//
        int m_Code;//
        string m_Description;//
        int m_Dir1;
        int m_Dir2;
        int m_Key;
        bool m_IsLocked;
        bool m_IsOpened;
        int m_Exit1;
        int m_Exit2;


};

void Doors::open(int loc, vector<Rooms> *rms){
        if(m_IsLocked == true) {
            //check inventory for key, then unlock door otherwise return saying dont have key
        }


        if (m_IsOpened == false) {
            m_IsOpened = true;

            rms->at(m_Exit1).setExits(m_Dir1, m_Exit2);            
            rms->at(m_Exit2).setExits(m_Dir2, m_Exit1);

            cout << "I have opened the door." << endl;
            return;
        } else if (m_IsOpened == true) {
            cout << "The door is already open." << endl;
            return;
        }
        cout << "There is no door to open here..." << endl;
        return;
}

//string word = "", int code = NONE, string description = "", int exit1 = NONE, int exit2 = NONE, int direction = NONE, bool isLocked = false, int key = NONE
void set_Doors (vector<Doors> * drs){
    drs->push_back(Doors("DOOR", MANSION_DOOR, "a old but sturdy door, cannot get through it without a key", ENTRANCE, FOYER, EAST));
    drs->push_back(Doors("DOOR", SERVANT_DOOR, "a old locked reinforced door, in copper letters it says \"Servents only\"...", HALLWAY, SHALLWAY, SOUTH));
    drs->push_back(Doors("DOOR", BEDROOM_DOOR, "a old locked door with golden accents", HALLWAY2, MBEDROOM, EAST));
    drs->push_back(Doors("DOOR", STUDY_DOOR, "a old wooden door with silver accents that is currently locked", LIBRARY, STUDY, EAST));
    drs->push_back(Doors("DOOR", VAULT_DOOR, "A vault door that needs a code...", MBEDROOM, VAULT, EAST));
}

void set_Nouns (vector<Nouns> * nns) {
        nns->push_back(Nouns("WELL", WELL, "a old well that seems to have something at the bottom", WELLROOM, false));
        nns->push_back(Nouns("MANSION_KEY", WELLROOM, "a old but usable key, it seems to go to the mansion", NONE, false)); //add it so its inside the well
        nns->push_back(Nouns("FLOWERS", FLOWERS, "on the side of the path contains old rotting flowers", PATH, false));
        nns->push_back(Nouns("FOUNTAIN", FOUNTAIN, "a old fountain, it says \"Throw five golden coins for [...]\"... it cuts off", ENTRANCE, false));
        nns->push_back(Nouns("SWORD", SWORD, "a rusted but usable sword", POND, false));
        nns->push_back(Nouns("FOOD", FOOD, "rotting food that smells terrible, lets get out of here", KITCHEN, false));
        nns->push_back(Nouns("SERVANT_KEY", SERVANT_KEY, "a old copper key, it is labeled servents key...", GARDEN, false)); //after defeating the weaping angel
        nns->push_back(Nouns("CHESTPLATE", CHESTPLATE, "a old rusting chestplate that still offers adequte protection", GUARDROOM, false));
        nns->push_back(Nouns("CLOTHES", CLOTHES, "a pile of old servants clothes, nothing of use", LAUNDRY, false));
        nns->push_back(Nouns("BARRELS", BARRELS, "a old barrel", STORAGE, false));
        nns->push_back(Nouns("CRATES", CRATES, "some wooden crates", STORAGE, false));
        nns->push_back(Nouns("BEDROOM_KEY", BEDROOM_KEY, "a exquisite golden key labeled \"Master Bedroom\"", STUDY, false));
        nns->push_back(Nouns("STUDY_KEY", STUDY_KEY, "A unlabled intricate silver key", MBATHROOM, false));
        nns->push_back(Nouns("NOTEBOOK", NOTEBOOK, "a old, left open notebook whose page says \"2341\"....", STUDY, false));
        nns->push_back(Nouns("COINS", COINS, "a golden coin stampted with the mansions insignia...", NONE, false)); //randomize
 
}

int main() {
    string command;
    string word_1;
    string word_2;

    vector<Nouns> nouns;
    set_Nouns(&nouns);

    vector<Doors> doors;
    set_Doors(&doors);


    for(int i = 0; i<NOUNS; i++){
        cout << nouns[i].getDesc() << endl;
    }

}