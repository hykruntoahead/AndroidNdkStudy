#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // int number = 3;
    // /**const**/ int*  pNum1 = &number;
    // *pNum1 = 20;
    // int *pNum2 = pNum1;
    // number *= 2;
    // cout << *pNum2 << endl;

    // int *pointToAnInt = new int;
    // pointToAnInt = 9;
    // cout << "The value at pointToAnInt: " << *pointToAnInt;
    // delete pointToAnInt;

    int *pointToAnInt = new int;
    int *pNumberCopy = pointToAnInt;
    *pNumberCopy = 30;
    cout << *pointToAnInt;
    delete pNumberCopy;
    // delete pointToAnInt;
    return 0;
}
