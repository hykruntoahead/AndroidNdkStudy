#include <iostream>
#include <string>
using namespace std;

#define ARRAY_LENGTH 25
#define PI 3.1416
#define MY_DOUBLE double
#define FAV_WHISKY "Jack Daniels"


/**
 * 定义常量时，更好的选择是使用关键字 const 和数据类型，因此下面的定义好得多：
 * const int ARRAY_LENGTH = 25; 
 * const double PI = 3.1416; 
 * const char* FAV_WHISKY = "Jack Daniels"; 
 * typedef double MY_DOUBLE; // typedef aliases a type 
 * 
 * /

int main()
{
    int numbers[ARRAY_LENGTH] = {0};
    cout << "Array's length: " << sizeof(numbers) /sizeof(int) << endl;

    cout << "Enter a radius: ";
    MY_DOUBLE radius = 0;
    // cin >> radius;
    radius = 11.91;
    cout << "Area is: " << PI * radius * radius << endl;

    string favotiteWhisky (FAV_WHISKY);
    cout << "My favorite drink is : " << FAV_WHISKY << endl;

    return 0;
}
