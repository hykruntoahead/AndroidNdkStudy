//以私有方式继承

// 从继承层次结构外部看，私有继承并非 is-a 关系。
// 私有继承使得只有子类才能使用基类的属性和方法，
// 因此也被称为 has-a 关系。如汽车Car　has-a 发动机 Motor

/**
 *  注意:
 *  如果有一个 RaceCar 类，它继承了 Car 类，则不管 RaceCar 和 Car 之间的继承关系是什么样的，
 * RaceCar 都不能访问基类 Motor 的公有成员和方法。这是因为 Car 和 Motor 之间是私有继承关系，
 * 这意味着除 Car 外，其他所有实体都不能访问基类 Motor 的公有或保护成员。
 * 换句话说，编译器在确定派生类能否访问基类的公有或保护成员时，
 * 考虑的是继承层次结构中最严格的访问限定符。
 * /

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

class Car : private Motor // private inheritance
{
public:
    void Move()
    {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};

int main()
{
    Car myDreamCar;
    myDreamCar.Move();
    // myDreamCar.PumpFuel();  error: ‘void Motor::PumpFuel()’ is inaccessible 
    return 0;
}