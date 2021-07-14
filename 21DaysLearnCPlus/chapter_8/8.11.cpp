//数组变量是指向第一个元素的指针
#include <iostream>
using namespace std;

int main()
{
    int myNumbers[5] ;
    int* pointToNums = myNumbers;
    
    cout << "pointToNums = " << hex << pointToNums << endl;

    cout << "&myNumbers[0] = " << hex << &myNumbers[0] << endl;

    return 0;
}
