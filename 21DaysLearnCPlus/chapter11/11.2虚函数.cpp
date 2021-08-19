//虚函数

/**
 * 通过使用关键字 virtual，可确保编译器调用覆盖版本。
 * 也就是说，如果 Swim( )被声明为虚函数，
 * 则将参数 myFish（其类型为 Fish&）设置为一个 Tuna 对象时，
 * myFish.Swim( )将执行 Tuna::Swim( )
 * */

#include <iostream>
using namespace std;

class Fish
{
public:
    virtual void Swim()
    {
        cout << "Fish swims!" << endl;
    }
};

class Tuna : public Fish
{
public:
    // override Fish::Swim
    void Swim()
    {
        cout << "Tuna swims!" << endl;
    }
};

class Carp : public Fish
{
public:
    // override Fish::Swim
    void Swim()
    {
        cout << "Carp swims!" << endl;
    }
};

void MakeFishSwim(Fish &inputFish)
{
    // calling virtual method Swim()
    inputFish.Swim();
}

int main()
{
    Tuna myDinner;
    Carp myLunch;

    //多态：将派生类对象视为基类对象，并执行派生类的 Swim( )实现
    // sending Tuna as Fish
    MakeFishSwim(myDinner);

    // sending Carp as Fish
    MakeFishSwim(myLunch);

    return 0;
}