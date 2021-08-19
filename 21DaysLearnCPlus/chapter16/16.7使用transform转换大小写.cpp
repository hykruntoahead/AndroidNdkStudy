
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;//std::transform

int main(){
    string originStr = "find my heart and follow it";
    cout << originStr << endl;

    //::tolower
    transform(originStr.begin(),originStr.end(),originStr.begin(),::toupper);

    cout << "The string converted to lower case is: " << endl;
    cout << originStr << endl << endl;

    return 0;
}