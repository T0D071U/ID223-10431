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

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 22;


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

void set_rooms(vector<Rooms> *rms) {//NORTH EAST SOUTH WEST
    rms->push_back(Rooms("GARDEN", NONE, GARDEN, NONE, NONE));
    rms->push_back(Rooms("STUDY", NONE, LIBRARY, NONE, NONE));
    rms->push_back(Rooms("WELL", NONE, NONE, PATH, NONE));
    rms->push_back(Rooms("KITCHEN", NONE, NONE, DINING_ROOM, NONE));
    rms->push_back(Rooms("LIBRARY", NONE, NONE, FAMILY_ROOM, NONE));
    rms->push_back(Rooms("GSBEDROOM", NONE, NONE, HALLWAY2, NONE));
    rms->push_back(Rooms("PATH", WELLROOM, NONE, ENTRANCE, NONE));
    rms->push_back(Rooms("DINING_ROOM", KITCHEN, FAMILY_ROOM, NONE, NONE));
    rms->push_back(Rooms("FAMILY_ROOM", LIBRARY, NONE, HALLWAY, DINING_ROOM));
    rms->push_back(Rooms("MBATHROOM", NONE, NONE, MBATHROOM, NONE));
    rms->push_back(Rooms("HALLWAY", FAMILY_ROOM, HALLWAY2, SHALLWAY, FOYER));
    rms->push_back(Rooms("HALLWAY2", GSBEDROOM, MBEDROOM, NONE, HALLWAY));
    rms->push_back(Rooms("ENTRANCE", PATH, FOYER, POND, NONE));
    rms->push_back(Rooms("FOYER", NONE, HALLWAY, NONE, ENTRANCE));
    rms->push_back(Rooms("MBEDROOM", MBATHROOM, VAULT, NONE, HALLWAY2));
    rms->push_back(Rooms("VAULT", NONE, NONE, NONE, MBEDROOM));
    rms->push_back(Rooms("POND", ENTRANCE, NONE, NONE, NONE));
    rms->push_back(Rooms("GUARDROOM", NONE, SHALLWAY, NONE, NONE));
    rms->push_back(Rooms("SHALLWAY", HALLWAY, SQUARTERS, LAUNDRY, GUARDROOM));
    rms->push_back(Rooms("SQUARTERS", NONE, NONE, NONE, SHALLWAY));
    rms->push_back(Rooms("LAUNDRY", SHALLWAY, STORAGE, NONE, NONE));
    rms->push_back(Rooms("STORAGE", NONE, NONE, NONE, LAUNDRY));
}
int main() {
    string command;
    string word_1;
    string word_2;

    vector<Rooms> rooms;
    set_rooms(&rooms);

    for(int i = 0; i<ROOMS; i++){

        cout << rooms[i].getDesc() << " -->" <<rooms[i].getExits(NORTH) << endl;         
    }

}