#include <iostream>
#include <vector>
using namespace std;



int main(int argc, char const *argv[])
{
    vector<int> integers {50,1,987,1001};

    for(size_t index = 0; index < integers.size(); ++ index){
        cout << "Element[" << index << "] = ";
        cout << integers[index] << endl;
    } 

    integers[2] = 2011;
    cout << "After replacement: " << endl;
    cout << "Element[2] = " << integers[2] << endl;

    return 0;
}
