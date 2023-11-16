#include <iostream>
#include <string>
#include <vector>
using namespace std;

//robot farm
class Robot {
    public:
        Robot(const string& giveName=""){   //constructor
            name = giveName;
        } 
        string GetName() const{
            return name;
        }
    private:
        string name;
};

class Gaggle {
    public:
        Gaggle(int spaces = 1){                           //constuctor
            robots.reserve(spaces);
        }
        void Add(const Robot& givenRobot) {
            robots.push_back(givenRobot);
        }
        void RollCall() const {
            for (vector<Robot>::const_iterator iter = robots.begin(); iter 
                != robots.end(); ++iter){
                    cout << iter->GetName() << endl;
            }
        }

    private:
        vector<Robot> robots;
};


int main(){

    return 0;
}