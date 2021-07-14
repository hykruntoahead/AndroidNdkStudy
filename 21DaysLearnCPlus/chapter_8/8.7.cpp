// 使用解除引用运算符（*）访问使用 new 分配的内存，并使用 delete 释放它
#include <iostream>

using namespace std;
int main()
{
    /* code */
    int *pointsToAnage = new int;

    // Use the allocated memory to store a number
    cout << "Enter your dog’s age: ";
    cin >> *pointsToAnage;

    // use indirection operator* to access value
    cout << "Age " << *pointsToAnage << " is stored at 0x" << hex << pointsToAnage << endl;
    delete pointsToAnage; // release memory

    return 0;
}
