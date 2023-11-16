#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {SPORTSHOP, CASINO, CARPARK, LOBBY, RESTAURANT, CORRIDOR, STOREROOM,
                POOL, GARDEN, POND, PUMPROOM};
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};
enum en_NOUNS {STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD};

const int NONE = -1;
const int DIRS = 4;
const int ROOOMS = 11;
const int VERBS = 8;
const int NOUNS = 6;

struct words {
    string word;
    int code;
};

struct room {
    string description;
    int exits_to_room[DIRS];
};

struct noun {
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
};

void set_rooms(room *rms) {
    rms[SPORTSHOP].description.assign("sports shop");
    rms[SPORTSHOP].exits_to_room[NORTH] = NONE;
    rms[SPORTSHOP].exits_to_room[EAST] = NONE;
    rms[SPORTSHOP].exits_to_room[SOUTH] = CARPARK;
    rms[SPORTSHOP].exits_to_room[WEST] = NONE;

    rms[CASINO].description.assign("bustling casino");
    rms[CASINO].exits_to_room[NORTH] = NONE;
    rms[CASINO].exits_to_room[EAST] = NONE;
    rms[CASINO].exits_to_room[SOUTH] = LOBBY;
    rms[CASINO].exits_to_room[WEST] = NONE;

    rms[CARPARK].description.assign("car park");
    rms[CARPARK].exits_to_room[NORTH] = SPORTSHOP;
    rms[CARPARK].exits_to_room[EAST] = LOBBY;
    rms[CARPARK].exits_to_room[SOUTH] = NONE;
    rms[CARPARK].exits_to_room[WEST] = NONE;

    rms[LOBBY].description.assign("hotel lobby");
    rms[LOBBY].exits_to_room[NORTH] = NONE;
    rms[LOBBY].exits_to_room[EAST] = NONE;
    rms[LOBBY].exits_to_room[SOUTH] = NONE;
    rms[LOBBY].exits_to_room[WEST] = NONE;

    rms[RESTAURANT].description.assign("restaurant");
    rms[RESTAURANT].exits_to_room[NORTH] = NONE;
    rms[RESTAURANT].exits_to_room[EAST] = NONE;
    rms[RESTAURANT].exits_to_room[SOUTH] = NONE;
    rms[RESTAURANT].exits_to_room[WEST] = NONE;

    rms[CORRIDOR].description.assign("corridor");
    rms[CORRIDOR].exits_to_room[NORTH] = NONE;
    rms[CORRIDOR].exits_to_room[EAST] = NONE;
    rms[CORRIDOR].exits_to_room[SOUTH] = NONE;
    rms[CORRIDOR].exits_to_room[WEST] = NONE;

    rms[STOREROOM].description.assign("store room");
    rms[STOREROOM].exits_to_room[NORTH] = NONE;
    rms[STOREROOM].exits_to_room[EAST] = NONE;
    rms[STOREROOM].exits_to_room[SOUTH] = NONE;
    rms[STOREROOM].exits_to_room[WEST] = NONE;

    rms[POOL].description.assign("swimming pool area");
    rms[POOL].exits_to_room[NORTH] = NONE;
    rms[POOL].exits_to_room[EAST] = NONE;
    rms[POOL].exits_to_room[SOUTH] = NONE;
    rms[POOL].exits_to_room[WEST] = NONE;

    rms[GARDEN].description.assign("tranquil garden");
    rms[GARDEN].exits_to_room[NORTH] = NONE;
    rms[GARDEN].exits_to_room[EAST] = NONE;
    rms[GARDEN].exits_to_room[SOUTH] = NONE;
    rms[GARDEN].exits_to_room[WEST] = NONE;

    rms[POND].description.assign("patio with a fish pond");
    rms[POND].exits_to_room[NORTH] = NONE;
    rms[POND].exits_to_room[EAST] = NONE;
    rms[POND].exits_to_room[SOUTH] = NONE;
    rms[POND].exits_to_room[WEST] = NONE;

    rms[PUMPROOM].description.assign("damp pump room");
    rms[PUMPROOM].exits_to_room[NORTH] = NONE;
    rms[PUMPROOM].exits_to_room[EAST] = NONE;
    rms[PUMPROOM].exits_to_room[SOUTH] = NONE;
    rms[PUMPROOM].exits_to_room[WEST] = NONE;
}
 
void set_directions (words *dir) {
    dir[NORTH].code = NORTH;
    dir[NORTH].word = "NORTH";
    dir[EAST].code = EAST;
    dir[EAST].word = "EAST";
    dir[SOUTH].code = SOUTH;
    dir[SOUTH].word = "SOUTH";
    dir[WEST].code = WEST;
    dir[WEST].word = "WEST";
}

void set_verbs (words *vbs) {
    vbs[GET].code = GET;
    vbs[GET].word = "GET";
    vbs[DROP].code = DROP;
    vbs[DROP].word = "DROP";
    vbs[USE].code = USE;
    vbs[USE].word = "USE";
    vbs[OPEN].code = OPEN;
    vbs[OPEN].word = "OPEN";
    vbs[CLOSE].code = CLOSE;
    vbs[CLOSE].word = "CLOSE";
    vbs[EXAMINE].code = EXAMINE;
    vbs[EXAMINE].word = "EXAMINE";
    vbs[INVENTORY].code = INVENTORY;
    vbs[INVENTORY].word = "INVENTORY";
    vbs[LOOK].code = LOOK;
    vbs[LOOK].word = "LOOK";
}

void set_nouns (noun *nns) {
    
    nns[STORE_DOOR].word = "DOOR";
    nns[STORE_DOOR].code = STORE_DOOR;
    nns[STORE_DOOR].description = "a closed store room door";
    nns[STORE_DOOR].can_carry = false;
    nns[STORE_DOOR].location = CORRIDOR;
    
    nns[MAGNET].word = "MAGNET";
    nns[MAGNET].code = MAGNET;
    nns[MAGNET].description = "a magnet";
    nns[MAGNET].can_carry = true;
    nns[MAGNET].location = NONE;
        
    nns[METER].word = "METER";
    nns[METER].code = METER;
    nns[METER].description = "a parking meter";
    nns[METER].can_carry = false;
    nns[METER].location = CARPARK;

    nns[ROULETTE].word = "ROULETTE";
    nns[ROULETTE].code = ROULETTE;
    nns[ROULETTE].description = "a roulette wheel";
    nns[ROULETTE].can_carry = false;
    nns[ROULETTE].location = CASINO;
    
    nns[MONEY].word = "MONEY";
    nns[MONEY].code = MONEY;
    nns[MONEY].description = "some money";
    nns[MONEY].can_carry = true;
    nns[MONEY].location = NONE;
    
    nns[FISHROD].word = "ROD";
    nns[FISHROD].code = FISHROD;
    nns[FISHROD].description = "A fishing rod";
    nns[FISHROD].can_carry = false;
    nns[FISHROD].location = SPORTSHOP;
}

void section_command (string Cmd, string &wd1, string &wd2) {
    string sub_str;
    vector<string> words;
    char search = ' ';
    short int i, j;

    for(i=0; i < Cmd.size(); i++) {
        if(Cmd.at(i) != search) {
            sub_str.insert(sub_str.end(), Cmd.at(1));
        }

        if(i == Cmd.size() - 1) {
            words.push_back(sub_str);
            sub_str.clear();
        }

        if(Cmd.at(1) == search) {
            words.push_back(sub_str);
            sub_str.clear();
        }
    }

    for(i = words.size()-1; i> 0; i++) {
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
        
    }
}