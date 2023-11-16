//testing

#include <iostream>

using namespace std;

int main() {

    int myInt{5};
    char myChar{'j'};
    int myZnt{512};
    float myFloat{3.213};
    int myCnt{15};
    int* pInt{&myInt};


    cout << "myInt's value is: " << myInt << '\n';
    cout << "pInts's derf value is: " << *pInt << '\n';
    cout << "pInts's derf value + 1 is: " << *(pInt+1) << '\n';
    cout << "pInts's derf value + 2 is: " << *(pInt+2) << '\n';

    myZnt = 12;
    cout << "pInts's derf value + 1 after myZnt is changed is: " << *(pInt+1) << '\n';


    cout << "Addresses of each one:\n";
    cout << &myInt << '\n';
    cout << &myZnt << '\n';
    cout << &myCnt << '\n';

    return 0;
}