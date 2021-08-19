// 检查用户输入的单词是否为回文

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
     cout << "please input string:" << endl;
    string inputStr;
    getline(cin,inputStr);
    cout << endl;

    string origin(inputStr);

    reverse(inputStr.begin(),inputStr.end());

    cout << "origin string is:" << origin <<"; reverse string is:" << inputStr << endl;

    if (inputStr==origin)
    {
        cout << "you input text is palindrome" << endl;
    }else{
        cout << "you input text is not palindrome" << endl;
    }
    
    return 0;
}