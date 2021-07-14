//不能从外部访问类的私有数据成员和方法，但这条规则不适用于友元类和友元函数。要声明友元
// 类或友元函数，可使用关键字 friend

// 使用关键字 friend 让外部函数 DisplayAge( )能够访问私有数据成员

#include <iostream>
#include <string>
using namespace std;

class Human
{
    private:  
        //如果将下面一行注释掉,第２５行会出现编译报错
        friend void DisplayAge(const Human& person);
        string name;
        int age;
    public:
        Human(string humansName,int humansAge){
            name = humansName;
            age = humansAge;
        }      
};

void DisplayAge(const Human& person){
    cout << person.age << endl;
}

int main()
{
    Human firstMan("Adam",25);
    cout << "Accessing private member age via friend function: ";
    DisplayAge(firstMan);
    return 0;
}