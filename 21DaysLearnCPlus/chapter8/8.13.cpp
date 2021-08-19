// 使用运算符*对指针解除引用，以访问指向的值时，务必确保指针指向了有效的内存单元，否则程
// 序要么崩溃，要么行为不端。这看起来合乎逻辑，但一个非常常见的导致应用程序崩溃的原因就是无
// 效指针。指针无效的原因很多，但主要归结于糟糕的内存管理。

// 在存储布尔值的程序中错误地使用指针

#include <iostream>
using namespace std;

int main(){

    bool* isSunny;

    cout << "Is it sunny (y/n)? ";
    char userInput = 'y';
    cout << "char size = " << sizeof(userInput) << endl;
    cin >> userInput;

    if (userInput == 'y')
    {
        isSunny = new bool;
        *isSunny = true;
    }

    cout << "boolean flag sunny says : " << *isSunny << endl;

    delete isSunny;

    return 0;
}