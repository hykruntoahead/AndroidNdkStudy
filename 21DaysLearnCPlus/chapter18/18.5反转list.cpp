#include <list>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& container){
    for (auto element = container.cbegin();
            element != container.cend();
            ++element){
        cout << *element << ' ';
    }
    cout << endl;
}

int main(){
    std::list<int> linkInts{0,1,2,3,7,4,5};

    cout << "Initial contents of list:" << endl;
    DisplayContents(linkInts);

    linkInts.reverse();

    cout << "Contents of list after using reverse():" << endl;
    DisplayContents(linkInts);

    return 0;
}