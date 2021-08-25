#include <list>
#include <vector>
using namespace std;


int main()
{
    list<int> linkInts;
    list<int> listWith10Integers(10);

    list<int> listWith4InteferEach99(10,99);

    list<int> listCopyAnother(listWith4InteferEach99);

    vector<int> vecIntegers(10,2017);

    list<int> listConstainsCopyOfAnother(
        vecIntegers.cbegin(),vecIntegers.cend()
    );

    return 0;
}