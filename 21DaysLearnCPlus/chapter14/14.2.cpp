// 宏函数通常用于执行非常简单的计算。相比于常规函数调用，宏函数的优点在于，它们将在编译
// 前就地展开，因此在有些情况下有助于改善代码的性能.

#include <iostream>
#include<string>
using namespace std;

#define SQUARE(x) ((x) * (x))
#define PI 3.1416
#define AREA_CIRCLE(r) (PI * (r) * (r))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int main()
{
    cout << "Enter an integer: ";
    int num = 0;
    // cin >> num;
    num = 10;

    cout << "SQUARE(" << num << ") = " << SQUARE(num) << endl;
    cout << "Area of a circle with radius " << num << " is: "; 
    cout << AREA_CIRCLE(num) << endl; 
 
    cout << "Enter another integer: "; 
    int num2 = 0; 
//  cin >> num2; 
    num2 = 16;
 
    cout << "MIN(" << num << ", " << num2 << ") = "; 
    cout << MIN (num, num2) << endl; 
 
    cout << "MAX(" << num << ", " << num2 << ") = "; 
    cout << MAX (num, num2) << endl; 
  
    return 0;   
}