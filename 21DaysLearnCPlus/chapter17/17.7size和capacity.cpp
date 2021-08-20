#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void DisplayVector(const vector<T>& inVec){
    for (auto element = inVec.cbegin();
         element != inVec.cend();
          ++element){
        cout << *element << ' ';
    }
    cout << endl;
}


int main(){
    vector <int> integers (5);
    cout << "Vector of integers was instantiated with" << endl;
    cout << "Size: " << integers.size();
    cout << ", Capacity: " << integers.capacity() << endl;
    DisplayVector(integers);
    cout << "===========================" << endl;

    integers.push_back(666);
    cout << "After inserting an additional element... " << endl;
    cout << "Size: " << integers.size();
    cout << ", Capacity:" << integers.capacity() << endl;

    DisplayVector(integers);
    cout << "===========================" << endl;

    integers.push_back(777);
    cout << "After inserting yet another element... " << endl;
    cout << "Size: " << integers.size();
    cout << ", Capacity:" << integers.capacity() << endl;

    DisplayVector(integers);
    cout << "===========================" << endl;
    return 0;
}