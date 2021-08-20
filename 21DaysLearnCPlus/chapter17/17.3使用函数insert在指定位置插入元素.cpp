#include <vector>
#include <iostream>
using namespace std;

void DisplayVector(const vector<int>& inVec){

    for(auto element = inVec.cbegin();
            element != inVec.cend();
            ++ element){
                cout << *element << ' ';
            }
    
    cout << endl;
}

int main(){
    vector<int> integers(4,90);

    cout << "The initial contents of the vector: ";
    DisplayVector(integers);

    integers.insert(integers.begin(),25);

    integers.insert(integers.end(),2,45);

    cout << "Vector after inserting elements at beginning and end: ";

    DisplayVector(integers);

    vector<int> another(2,30);
    integers.insert(integers.begin()+1,another.begin(),another.end());

    cout << "Vector after inserting contents from another vector: ";
    cout << "in the middle: " << endl;
    DisplayVector(integers);

    return 0;
}