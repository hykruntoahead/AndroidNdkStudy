// 使用 new[…]分配内存，并使用 delete[]释放它们

#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << "How many integers shall I reserve memory for?" << endl;
    int numEntries = 0;
    //动态内存分配 127
    cin >> numEntries;
    int *myNumbers = new int[numEntries];

    cout << "Memory allocated at:" << myNumbers << hex << endl;

    // de-allocate before exiting
    delete[] myNumbers;

    return 0;
}