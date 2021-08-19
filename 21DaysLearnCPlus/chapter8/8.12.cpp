//使用解除引用运算符（*）访问数组中的元素以及将数组运算符（[]）用于指针

#include <iostream>
using namespace std;

int main()
{
    const int ARRAY_LEN = 5;

    int myNumbers[ARRAY_LEN] = {24,-1,365,-999,2011};

    int* pointToNums = myNumbers;

    cout << "Display array using pointer syntax,operator*" << endl;

    for (int index = 0; index < ARRAY_LEN; index++)
    {
        cout << "array[" << index << "]=" << *(pointToNums + index) << endl;
    }
    
    return 0;
}