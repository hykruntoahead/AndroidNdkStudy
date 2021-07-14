//内联函数 inline

// 只执行将数字翻倍等简单操作的函数非常适合声明为内联的.
// 因为相对于实际执行函数体所需时间执行函数调用的开销可能非常高.

#include <iostream>
using namespace std;

double Area(double Pi = 3.14, double radius);

inline long DoubleNum(int inputNum)
{
    return inputNum * 2;
}

int main()
{
    // cout << "Enter an integer:";
    // int inputNum = 0;
    // cin >> inputNum;

    // //call inline function
    // cout << "Double is:" << DoubleNum(inputNum) << endl;

    cout << "Area is:" << Area(10) << endl;
    return 0;
}

double Area(double Pi = 3.14, double radius)
{
    return Pi * radius * radius;
}