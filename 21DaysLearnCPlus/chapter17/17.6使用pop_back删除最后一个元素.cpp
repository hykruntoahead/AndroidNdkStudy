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
    vector<int> integers;

    integers.push_back(50);
    integers.push_back(1);
    integers.push_back(987);
    integers.push_back(1001);

    cout << "Vector contains " << integers.size() << "elements: ";
    DisplayVector(integers);

    integers.pop_back();

    cout << "After a call to pop_back()" << endl;
    cout << "Vector contains " << integers.size() << "elements: ";
    DisplayVector(integers);

    return 0;
}