#include <map>
#include <iostream>
#include <string>

using namespace std;

typedef map<int,string> MAP_INT_STRING;
typedef multimap <int,string> MMAP_INT_STRING;

template <typename T>
void DisplayContents(const T& cont){
    for(auto element = cont.cbegin();
            element != cont.cend();
            ++element)
            cout << element->first << " -> " << element -> second << endl;

    cout << endl;
}

int main(){
    MAP_INT_STRING mapIntToStr;

    mapIntToStr.insert(MAP_INT_STRING::value_type(3,"Three"));

    mapIntToStr.insert(make_pair(-1,"Minus One"));

    mapIntToStr.insert(pair<int,string>(1000,"One Thousand"));

    mapIntToStr[1000000] = "one Million";

    cout << "The map contains " << mapIntToStr.size();
    cout << " key-value pairs.They are: " << endl;
    DisplayContents(mapIntToStr);


    MMAP_INT_STRING mmapIntToStr(mapIntToStr.cbegin(),mapIntToStr.cend());

    mmapIntToStr.insert(make_pair(1000,"Thousand"));

    cout << endl << "The multimap contains " << mmapIntToStr.size();
    cout << " key-value pairs. They are: " << endl;
    cout << "The elements in the multimap are: " << endl;
    DisplayContents(mmapIntToStr);

    cout << "The number of pairs in the multimap with 100 as their key: "
    << mmapIntToStr.count(1000) << endl;

    return 0;
}