//虚函数表

// 对两个相同的类（一个包含虚函数，另一个不包含）进行比较，
// 证明确实存在隐藏的虚函数表指针

#include <iostream>
using namespace std;

class SimpleClass
{
    int a, b;

public:
    void DoSomething() {}
};

class Base
{
    int a, b;

//添加关键字 virtual 带来的影响是，编译器将为 Base 类生成一个虚函数表，并其虚函数表指针（一个隐藏成员）预留空间。
public:
    virtual void DoSomething() {}
};

int main()
{
    cout << "sizeof(SimpleClass) = " << sizeof(SimpleClass) << endl; //8
    cout << "sizeof(Base) = " << sizeof(Base) << endl; //16

    return 0;
}