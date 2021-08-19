// 使用 string::erase 从指定偏移位置或迭代器指定的位置开始截短字符串

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    string sampleStr("Hello String! Wake up to a beautiful day!");
    cout <<sampleStr << endl << endl;

    cout << "Truncating the second sentence: " << endl;
    sampleStr.erase(13,28);
    cout << sampleStr << endl << endl;


    string::iterator iCharS = find(sampleStr.begin(),
                                sampleStr.end(), 'S');

    if (iCharS != sampleStr.end()){
        sampleStr.erase(iCharS);
    }

    cout << sampleStr << endl << endl;


    cout << "Erasing a range between begin() and end(): " <<endl;
    sampleStr.erase(sampleStr.begin(),sampleStr.end());

    if (sampleStr.length() == 0){
        cout << "The string is empty!" << endl;
    }
    
    return 0;
}