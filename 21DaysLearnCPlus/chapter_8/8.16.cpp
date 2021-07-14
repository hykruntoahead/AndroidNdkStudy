// 使用 new(nothrow)，它在分配内存失败时返回 NULL 
#include <iostream>
using namespace std;

int main(){
    double* pointsToManyNums = new(nothrow) double[0x1fffffffffffffff];

    if (pointsToManyNums)
    {
         delete[] pointsToManyNums;
    }else
    {
        cout << "Memory allocation failed.Ending program" << endl;
    }
    
    return 0;
}