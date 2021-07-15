// 保护继承

/**
 * 保护继承与私有继承的类似之处如下：
•  它也表示 has-a 关系；
•  它也让派生类能够访问基类的所有公有和保护成员；
•  在继承层次结构外面，也不能通过派生类实例访问基类的公有成员。

在保护继承层次结构中，子类的子类（即 Derived2）能够访问 Base 类的公有和保护成员，如程序
清单 10.9 所示。如果 Derived 和 Base 之间的继承关系是私有的，就不能这样做。
 */

#include <iostream>
using namespace std;

class Motor
{
public:
    void SwitchIgnition()
    {
        cout << "Ignition ON" << endl;
    }
    void PumpFuel()
    {
        cout << "Fuel in cylinders" << endl;
    }
    void FireCylinders()
    {
        cout << "Vroooom" << endl;
    }
};

class Car : protected Motor
{
public:
    void Move()
    {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};

class RaceCar : protected Car
{
public:
    void Move()
    {
        SwitchIgnition(); // RaceCar has access to members of
        PumpFuel();       // base Motor due to "protected" inheritance
        FireCylinders();  // between RaceCar & Car, Car & Motor
        FireCylinders();
        FireCylinders();
    }
};

int main()
{
    RaceCar myDreamCar;
    myDreamCar.Move();

    return 0;
}