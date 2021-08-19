
//使用加法赋值运算符（+=）或 append( )拼接字符串
#include <string>
#include <iostream>
using namespace std;

int main(){
    string sampleStr1("Hello");
    string sampleStr2(" Stl String!");

    sampleStr1 += sampleStr2;
    cout << sampleStr1 << endl << endl;

    string sampleStr3(" Fun is not needing to use pointers!");
    sampleStr1.append(sampleStr3);
    cout << sampleStr1 << endl << endl;

    return 0;
}