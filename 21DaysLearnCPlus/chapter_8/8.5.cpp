// 使用指针和解除引用运算符操纵数据

#include <iostream>
using namespace std;

int main()
{
    int dogsAge = 30;

    cout << "Initialized dogsAge = " << dogsAge << endl;

    int* pointsToAnage = &dogsAge;

    *pointsToAnage = 18;

    cout << "DogsAge = " << dogsAge << endl;
    cout << "point of DogsAge value = " << *pointsToAnage << endl;

    return 0;
}
