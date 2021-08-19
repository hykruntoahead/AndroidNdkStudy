
//编写一个程序，显示字符串 Good day String! Today is beautiful!中每个 a 所在的位置。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string test = "Good day String! Today is beautiful!";
    
    size_t findPos = test.find('a',0);

    while(findPos != string::npos){
        cout << "find a on position:" << findPos <<",";
        findPos = test.find('a',findPos+1);
    }

    cout << endl;
}