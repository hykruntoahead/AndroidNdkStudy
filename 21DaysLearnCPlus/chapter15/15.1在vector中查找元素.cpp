#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    //隐式创建并调用无参构造器
    vector<int> intArray;

    intArray.push_back(50);
    intArray.push_back(2991);
    intArray.push_back(23);
    intArray.push_back(9999);

    cout << "The contents of the vector are:" <<endl;

    //  c++11 auto arrInterator = intArray.begin();
    vector <int>::iterator arrInterator = intArray.begin();

    while (arrInterator != intArray.end())
    {
        cout << *arrInterator << endl;

        ++ arrInterator;
    }
    
    vector <int>::iterator elFound = find(intArray.begin(),
            intArray.end(),23);

    if (elFound != intArray.end())
    {
        int elPos = distance(intArray.begin(),elFound);
        cout << "Value " << *elFound;
        cout << " found in the vector at position:" << elPos <<endl;
    }

    return 0;
}