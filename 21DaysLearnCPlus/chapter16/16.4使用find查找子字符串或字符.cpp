// 使用 string::find( )查找子字符串或字符
#include <string>
#include <iostream>

int main(){
    using namespace std;

    string sampleStr ("Good day String ! Today is beautiful!");
    cout << "Sample string is: " << endl << sampleStr << endl << endl;

    size_t charPos = sampleStr.find("day",0);
    // string::npos -1
    if (charPos != string::npos)
    {
       cout << "Fiest instance \"day\" at pos " << charPos << endl;
    }else{
        cout << "Substring not found." << endl;
    }
    cout << "Locating all instance of substring \"day\"" << endl;

    size_t subStrPos = sampleStr.find("day",0);

    while(subStrPos != string::npos){
        cout << "\"day\" found at position " << subStrPos << endl;

        size_t searchOffset = subStrPos +1;

        subStrPos = sampleStr.find("day",searchOffset);
    }
    
    return 0;
}