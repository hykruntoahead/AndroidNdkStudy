// 虚继承。如果派生类可能被用作基类，派生它是最好使用关键字 virtual.

// 在继承层次结构中使用关键字virtual，将基类 Animal 的实例个数限定为1

/**
 *  C++关键字 virtual 的含义随上下文而异（我想这样做的目的很可能是为了省事），对其含
义总结如下：
在函数声明中，virtual 意味着当基类指针指向派生对象时，通过它可调用派生类的相应
函数。
从 Base 类派生出 Derived1 和 Derived2 类时，如果使用了关键字 virtual，则意味着再从
Derived1 和 Derived2 派生出 Derived3 时，每个 Derived3 实例只包含一个 Base 实例。
也就是说，关键字 virtual 被用于实现两个不同的概念。
 */

#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal constructor" << endl;
    }

    // sample member
    int age;
};

class Mammal : public virtual Animal
{
};

class Bird : public virtual Animal
{
};

class Reptile : public virtual Animal
{
};

class Platypus /**final **/ : public Mammal, public Bird, public Reptile
{
public:
    Platypus()
    {
        cout << "Platypus constructor" << endl;
    }
};

int main()
{
    Platypus duckBilledP;

    // no compile error as there is only one Animal::age
    duckBilledP.age = 25;

    return 0;
}