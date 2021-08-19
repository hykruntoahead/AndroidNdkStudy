#include <string>
#include <iostream>

int main(){
    using namespace std;

    const char* constCstyleString = "Hello String!";
    cout << "Constant string is: " << constCstyleString << endl;

    std::string strFormConst(constCstyleString);//构造函数char*方式
    cout << "strFromConst is: " << strFormConst << endl;

    std::string str2 ("Hello String!");
    std::string str2Copy(str2);//构造函数string方式
    cout << "str2Copy is: " << str2Copy << endl;

    //初始化一个字符串保留前５个字符
    std::string strPartialCopy(constCstyleString,5);
    cout << "strPartialCopy is:" << strPartialCopy << endl;

    //初始化一个字符串包含10个a
    std::string strRepeatChars(10,'a');
    cout << "strRepeatChars is: " << strRepeatChars << endl;

    return 0;
}

/**
 * copy chars to chars on C Style
 * const char* constCStyleString = "Hello World!"; 
 * // To create a copy, first allocate memory for one... 
 * char* copy = new char [strlen (constCStyleString) + 1]; 
 * strcpy (copy, constCStyleString); // The copy step 
 * // deallocate memory after using copy 
 * delete [] copy
 * /