//检查使用 new 发出的分配请求是否得到满足

// 异常处理—在 new 失败时妥善地退出

#include <iostream>
using namespace std;

int main()
{
    try
    {

        double *pointsToManyNums = new double[0x1ffffffffffff];

        delete[] pointsToManyNums;
    }catch (bad_alloc)
    {
        cout << "Memory allocation failed.Ending program " << endl;
    }

    return 0;
}
