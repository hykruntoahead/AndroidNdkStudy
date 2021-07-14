#include <iostream>
#include <string>
using namespace std;

//接受带默认值的参数的默认构造函数并使用初始化列表来设置成员

// 也可使用关键字 constexpr 将构造函数定义为常量表达式。在有助于提高性能的情况下，
// 可在构造函数的声明中使用这个关键字，如下所示：
// class Sample 
// { 
// const char* someString; 
// public: 
//  constexpr Sample(const char* input) 
//  :someString(input) 
//  { // constructor code } 
// };  

class Human{
    private:
        int age;
        string name;

    public:
        Human(string humansName = "Adam",int humansAge = 25):name(humansName),age(humansAge)
        {
            cout << "Constructed ahuman called " << name;
            cout << "," << age << " years old" << endl;
        }
};

int main ()
{
    Human adam;
    Human eve("Eve",18);

    return 0;
}