#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> integers{50,1,987,1001};

    vector<int> ::const_iterator element = integers.cbegin();

    while(element != integers.end()){
        size_t index = distance(integers.cbegin(),element);

        cout << "Element at position ";
        cout << index << " is: " << *element << endl;

        ++element;
    }

    return 0;
}