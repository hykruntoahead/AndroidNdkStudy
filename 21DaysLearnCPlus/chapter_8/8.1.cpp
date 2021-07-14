#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int age = 30;
    const double Pi = 3.1416;

    //use to find the address in memory
    cout << "Integer age is located at : " << &age << endl;
    cout << "Integer age is located at : " << sizeof(&age) << endl;
    cout << "Double Pi is located at : " << &Pi << endl;
    cout << "Double Pi is located at : " << sizeof(&Pi) << endl;
    return 0;
}
