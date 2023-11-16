// Timothy Deahl ID233

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    cout <<  "You have " << inventory.size() << " items.\n";

    cout << "\nYour Items:\n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        cout << inventory[i] << endl;
    }

    return 0;
}