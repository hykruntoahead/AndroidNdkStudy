#include <set>
#include <iostream>
using namespace std;

int main(){
    set<int> setInts{43,78,-1,124};

    for(auto element = setInts.cbegin();
            element != setInts.cend();
            ++element){
                cout << *element << endl;
    }

    auto elementFound = setInts.find(-1);

    if (elementFound != setInts.end()){
        cout << "Element " << *elementFound << "found!" << endl;
    }else{
        cout << "Element not found in set!" << endl;
    }
 
    auto anotherFind = setInts.find(12345);

    if (anotherFind != setInts.end()){
        cout << "Element " << *anotherFind << "found!" << endl;
    }else{
        cout << "Element 12345 not found in set!" << endl;
    }
    
    return 0;
}