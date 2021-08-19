// 基类、派生类及其成员的构造顺序和析构顺序


/* 实例化 Tuna
对象时，将从继承层次结构顶部开始，因此首先实例化 Tuna 对象的 Fish 部分。
为此，首先实例化 Fish的成员属性，即 Fish::dummy。构造好成员属性（如 dummy）后，将调用 Fish 的构造函数。
构造好基类部分后，将实例化 Tuna 部分—
 首先实例化成员 Tuna::dummy，再执行构造函数 Tuna::Tuna( )的代码。
 输出表明，析构顺序正好相反。*/



#include <iostream>
using namespace std;

class FishDummyMember
{
public:
    FishDummyMember()
    {
        cout << "FishDummyMember constructor" << endl;
    }

    ~FishDummyMember()
    {
        cout << "FishDummyMember destructor" << endl;
    }
};

class Fish
{
protected:
    FishDummyMember dummy;

public:
    // Fish constructor
    Fish()
    {
        cout << "Fish constructor" << endl;
    }
    
    ~Fish()
    {
        cout << "Fish destructor" << endl;
    }
};

class TunaDummyMember
{
public:
    TunaDummyMember()
    {
        cout << "TunaDummyMember constructor" << endl;
    }

    ~TunaDummyMember()
    {
        cout << "TunaDummyMember destructor" << endl;
    }
};

class Tuna : public Fish
{
private:
    TunaDummyMember dummy;

public:
    Tuna()
    {
        cout << "Tuna constructor" << endl;
    }
    ~Tuna()
    {
        cout << "Tuna destructor" << endl;
    }
};

int main()
{
    Tuna myDinner;
}