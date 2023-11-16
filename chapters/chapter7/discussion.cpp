// Discussion Assignment

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> names;

    names.push_back("Batman");
    names.push_back("Robin");
    names.push_back("The Joker");

    for(int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    return 0;
}