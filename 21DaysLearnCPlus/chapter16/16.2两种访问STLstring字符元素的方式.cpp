/**
 * 
 * 要访问 STL string 的字符内容，
 * 可使用迭代器，也可采用类似于数组的语法并使用下标运算符（[]）
 * 提供偏移量。要获得 string 对象的 C 风格表示，可使用成员函数 c_str ()
 *  */

#include <string>
#include <iostream>

int main(){
    using namespace std;

    string stlString ("STL String");

    cout << "Display elements in string using array-syntax: " << endl;

    for (size_t charCounter = 0; 
        charCounter < stlString.length(); 
        ++ charCounter){
        cout << "Character [" << charCounter << "] is: ";
        cout << stlString[charCounter] << endl;
    }

    cout << endl;

    cout << "Display elements in string using iterators: " << endl;
    int charOffset = 0;
    string::const_iterator charLocator;

    for(auto charLocator = stlString.cbegin();
        charLocator != stlString.cend();
        ++charLocator){
            cout << "Character [" << charOffset ++ << "] is: ";
            cout << *charLocator << endl;
        }
    
    cout << endl;


cout << "The char* representation of the string is: ";
cout << stlString.c_str() << endl;

return 0;
}