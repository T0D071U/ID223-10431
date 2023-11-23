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
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, EQUIP, ATTACK};
enum en_NOUNS {WELL, MANSION_KEY, FLOWERS, FOUNTAIN, SWORD, 
                FOOD, SERVANT_KEY, CHESTPLATE, CLOTHES, BARRELS, CRATES, 
                BEDROOM_KEY, STUDY_KEY, NOTEBOOK, COINS};
enum en_DOORS {MANSION_DOOR, SERVANT_DOOR, BEDROOM_DOOR, STUDY_DOOR, VAULT_DOOR};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 11;
const int VERBS = 10;
const int NOUNS = 14;
const int DOORS = 5;


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




void set_rooms(vector<Rooms> *rms) {//NORTH EAST SOUTH WEST
    rms->push_back(Rooms("a old overgrown garden", NONE, NONE, LIBRARY, NONE));
    rms->push_back(Rooms("a diaplidated study", NONE, NONE, NONE, NONE));
    rms->push_back(Rooms("a small patch of land with a old wishing well", NONE, NONE, PATH, NONE));
    rms->push_back(Rooms("a run down kitchen filled with mice", NONE, NONE, DINING_ROOM, NONE));
    rms->push_back(Rooms("a haunted library", GARDEN, NONE, FAMILY_ROOM, NONE));
    rms->push_back(Rooms("a guest bedroom, missing the bed", NONE, NONE, HALLWAY2, NONE));
    rms->push_back(Rooms("a old worn down path filled with dead flowers", WELLROOM, NONE, ENTRANCE, NONE));
    rms->push_back(Rooms("a old dinning room with rotting food", KITCHEN, FAMILY_ROOM, NONE, NONE));
    rms->push_back(Rooms("a family room from nightmares", LIBRARY, NONE, HALLWAY, DINING_ROOM));
    rms->push_back(Rooms("a surprisingly clean bathroom", NONE, NONE, MBEDROOM, NONE));
    rms->push_back(Rooms("a hallway with many doors", FAMILY_ROOM, HALLWAY2, NONE, FOYER));
    rms->push_back(Rooms("another hallway with more doors", GSBEDROOM, NONE, NONE, HALLWAY));
    rms->push_back(Rooms("the area just before the mansion", PATH, NONE, POND, NONE));
    rms->push_back(Rooms("the once grand foyer", NONE, HALLWAY, NONE, NONE));
    rms->push_back(Rooms("a very ran down master bedroom", MBATHROOM, NONE, NONE, NONE));
    rms->push_back(Rooms("a old but sturdy vault", NONE, NONE, NONE, NONE));
    rms->push_back(Rooms("a small pond that is on the south-west side of the mansion", ENTRANCE, NONE, NONE, NONE));
    rms->push_back(Rooms("a old guards room", NONE, SHALLWAY, NONE, NONE));
    rms->push_back(Rooms("a tight servants hallway", NONE, SQUARTERS, LAUNDRY, GUARDROOM));
    rms->push_back(Rooms("a small servants quarters", NONE, NONE, NONE, SHALLWAY));
    rms->push_back(Rooms("a old laundry room", SHALLWAY, STORAGE, NONE, NONE));
    rms->push_back(Rooms("a diaplidated storage room", NONE, NONE, NONE, LAUNDRY));
}
 
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
        //nns->push_back(Nouns("COINS", COIN1, "a golden coin stampted with the mansions insignia...", NONE, false)); //randomize
        //nns->push_back(Nouns("COINS", COIN2, "a golden coin stampted with the mansions insignia...", NONE, false)); //randomize
        //nns->push_back(Nouns("COINS", COIN3, "a golden coin stampted with the mansions insignia...", NONE, false)); //randomize
        //nns->push_back(Nouns("COINS", COIN4, "a golden coin stampted with the mansions insignia...", NONE, false)); //randomize
        //nns->push_back(Nouns("COINS", COIN5, "a golden coin stampted with the mansions insignia...", NONE, false)); //randomize
 
}

void set_Doors (vector<Doors> * drs){
    drs->push_back(Doors("DOOR", MANSION_DOOR, "a old but sturdy door, cannot get through it without a key", ENTRANCE, FOYER, EAST));
    drs->push_back(Doors("DOOR", SERVANT_DOOR, "a old locked reinforced door, in copper letters it says \"Servents only\"...", HALLWAY, SHALLWAY, SOUTH));
    drs->push_back(Doors("DOOR", BEDROOM_DOOR, "a old locked door with golden accents", HALLWAY2, MBEDROOM, EAST));
    drs->push_back(Doors("DOOR", STUDY_DOOR, "a old wooden door with silver accents that is currently locked", LIBRARY, STUDY, EAST));
    drs->push_back(Doors("DOOR", VAULT_DOOR, "A vault door that needs a code...", MBEDROOM, VAULT, EAST));
}

void section_command (string Cmd, string &wd1, string &wd2) {
    string sub_str;
    vector<string> words;
    char search = ' ';
    short int i, j;

    for(i=0; i < Cmd.size(); i++) {
        if(Cmd.at(i) != search) {
            sub_str.insert(sub_str.end(), Cmd.at(i));
        }

        if(i == Cmd.size() - 1) {
            words.push_back(sub_str);
            sub_str.clear();
        }

        if(Cmd.at(i) == search) {
            words.push_back(sub_str);
            sub_str.clear();
        }
    }

    for(i = words.size() - 1; i > 0; i--) {
        if(words.at(i) == "") {
            words.erase(words.begin() + i);
        }
    }

    for(i = 0; i < words.size(); i++){
        for(j=0; j < words.at(i).size(); j++){
            if(islower(words.at(i).at(j))){
                words.at(i).at(j) = toupper(words.at(i).at(j));
            }
        }
    }

    if(words.size() == 0) {
        cout << "No command given" << endl;
    }

    if(words.size() == 1) {
        wd1 = words.at(0);
    }

    if(words.size() == 2) {
        wd1 = words.at(0);
        wd2 = words.at(1);
    }

    if(words.size() > 2){
        cout << "Command too long. Only type one or two words " <<
                "(direction or verb and noun)" << endl;
    }
}

void look_around (int loc, vector<Rooms> *rms, vector<Words> *dir, vector<Nouns> *nns, vector<Doors> *drs) {
    int i;

    cout << "I am in a " << rms->at(loc).getDesc() << ".\n" << endl;

    for (i = 0; i < DIRS; i++) {
        if (rms->at(loc).getExits(i) != NONE) {
            cout << "There is an exit " << dir->at(i).getWord() << " to a " //taking saying there is a exit EAST to a CARPARK is what its trying to do
            << rms->at(rms->at(loc).getExits(i)).getDesc() << "." << endl;
        }
    }

    for (i=0; i < NOUNS; i++) {
        if(nns->at(i).getLocation() == loc) {
            cout << "I see " << nns->at(i).getDesc() << "." << endl;
        }
    }

    for (i=0; i < DOORS; i++) {
        if(drs->at(i).getExits(0) == loc || drs->at(i).getExits(1) == loc) {
            cout << "I see " << drs->at(i).getDesc() << "." << endl;
        }
    }
}

bool parser (int &loc, string wd1, string wd2, vector<Words> *dir, vector<Words> *vbs, vector<Rooms> *rms, vector<Nouns> *nns, vector<Doors> *drs) {

    int i;
    for(i=0; i< DIRS; i++) {
        if(wd1 == dir->at(i).getWord()) {
            if(rms->at(loc).getExits(dir->at(i).getCode()) != NONE) {
                loc = rms->at(loc).getExits(dir->at(i).getCode());
                cout << "I am now in a " << rms->at(loc).getDesc() << "." << endl;
                return true;
            } else {
                cout << "No exit that way." << endl;
                return true;
            }
        }
    }

    int VERB_ACTION = NONE;
    int NOUN_MATCH = NONE;

    for (i=0; i < VERBS; i++) {
        if(wd1 == vbs->at(i).getWord()) {
            VERB_ACTION = vbs->at(i).getCode();
            break;
        }
    }

    if(wd2 != "") {
        for (i = 0; i < NOUNS; i++){
            if(wd2 == nns->at(i).getWord()) {
                NOUN_MATCH = nns->at(i).getCode();
                break;
            } 
        }
        for(i=0; i < DOORS; i++){
            if (wd2 == drs->at(i).getWord()){

                if(drs->at(i).getExits(0) == loc || drs->at(i).getExits(1) == loc){
                    NOUN_MATCH = drs->at(i).getCode();
                    break;
                }
            }
        }
        
    
    }

    if(VERB_ACTION == NONE) {
        cout << "No valid command entered." << endl;
        return true;
    }

    if(VERB_ACTION == LOOK) {
        look_around(loc, rms, dir, nns, drs);
        return true;
    }

    switch(NOUN_MATCH) {// change to for statement, switch gets too long for same values
    case MANSION_DOOR:
        drs->at(MANSION_DOOR).open(loc, rms);
        return true;
    case SERVANT_DOOR:
        drs->at(SERVANT_DOOR).open(loc, rms);
        return true;
    case BEDROOM_DOOR:
        drs->at(BEDROOM_DOOR).open(loc, rms);
        return true;
    case STUDY_DOOR:
        drs->at(STUDY_DOOR).open(loc, rms);
        return true;
    case VAULT_DOOR:
        drs->at(VAULT_DOOR).open(loc, rms);
        return true;
    default:
        cout << "Opening that is not possible." << endl;
        return true;
    }

    
    return false;
}

int main() {
    string command;
    string word_1;
    string word_2;

    vector<Rooms> rooms;
    set_rooms(&rooms);

    vector<Words> directions;
    set_directions(&directions);

    vector<Words> verbs;
    set_verbs(&verbs);

    vector<Nouns> nouns;
    set_Nouns(&nouns);

    vector<Doors> doors;
    set_Doors(&doors);

    int location = ENTRANCE;

    while(word_1 != "QUIT") {
        command.clear();
        parser(location, "LOOK", "", &directions, &verbs, &rooms, &nouns, &doors);
        cout << "\nWhat shall I do? ";
        getline(cin, command);

        word_1.clear();
        word_2.clear();

        section_command(command, word_1, word_2);

        if(word_1 != "QUIT") {
            parser(location, word_1, word_2, &directions, &verbs, &rooms, &nouns, &doors);
        }
        cout << endl;
    }
    return 0;
}