/**
 * 
 * 不能实例化的基类被称为抽象基类，这样的基类只有一个用途，那就是从它派生出其他类。
 * 在 C++中，要创建抽象基类，可声明纯虚函数。
 * 以下述方式声明的虚函数被称为纯虚函数：
 * class AbstractBase 
 * { 
 * public: 
 * virtual void DoSomething() = 0; // pure virtual method 
 * }; 
 * 该声明告诉编译器，AbstractBase 的派生类必须实现方法 DoSomething( )
 * */

// Fish 是 Tuna 和 Carp 的抽象基类

// 抽象基类常被简称为 ABC

#include <iostream>
using namespace std;

class Fish
{
public:
    // define a pure virtual function Swim 纯虚函数
    virtual void Swim() = 0;
};

class Tuna : public Fish
{

public:
    void Swim()
    {
        cout << "Tuna swims fast in the sea! " << endl;
    }
};

class Carp : public Fish
{
    void Swim()
    {
        cout << "Carp swims slow in the lake!" << endl;
    }
};

void MakeFishSwim(Fish &inputFish)
{
    inputFish.Swim();
}

int main()
{
    // Fish myFish; // Fails, cannot instantiate an ABC
    Carp myLunch;
    Tuna myDinner;

    MakeFishSwim(myLunch);
    MakeFishSwim(myDinner);

    return 0;
}