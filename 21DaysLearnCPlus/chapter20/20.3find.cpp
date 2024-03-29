#include <map>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void DisplayContents(const T& cont){
    for(auto element = cont.cbegin();
        element != cont.cend();
        ++element)
        cout << element->first << " -> " << element->second << endl;

    cout << endl; 
}

int main(){
    map<int,string> mapIntToStr;

    mapIntToStr.insert(make_pair(3,"Three"));
    mapIntToStr.insert(make_pair(45,"Forty Five"));
    mapIntToStr.insert(make_pair(-1,"Minus One"));
    mapIntToStr.insert(make_pair(1000,"Thousand"));

    cout << "The multimap contains " << mapIntToStr.size();
    cout << " key-value pairs. They are: " << endl;

    DisplayContents(mapIntToStr);

    cout << "Enter the key you wish to find: ";
    int key = 0;
    cin >> key;

    auto pairFound = mapIntToStr.find(key);
    if (pairFound != mapIntToStr.end()){
        cout << "key " << pairFound->first << " points to Value: ";
        cout << pairFound->second << endl;
    }else{
        cout << "Sorry, pair with key " << key << "not in map " << endl;
    }

    return 0;
}