#include <list>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& container){
    for(auto element = container.cbegin();
        element != container.cend(); 
        ++ element)
        cout << *element << ' ';
    
    cout << endl;
}

int main(){
    list<int> linkIntes1;

    linkIntes1.insert(linkIntes1.begin(),2);
    linkIntes1.insert(linkIntes1.begin(),1);

    linkIntes1.insert(linkIntes1.end(),3);
    DisplayContents(linkIntes1);


    list<int> linkIntes2;

    linkIntes2.insert(linkIntes2.begin(),4,0);
    cout << "linkIntes2 size=" << linkIntes2.size() << " and values= ";
    DisplayContents(linkIntes2);


    list<int> linkInts3;
    linkInts3.insert(linkInts3.begin(),linkIntes1.begin(),linkIntes1.end());
    DisplayContents(linkInts3);

    linkInts3.insert(linkInts3.end(),linkIntes2.begin(),linkIntes2.end());
    DisplayContents(linkInts3);

    return 0;
}