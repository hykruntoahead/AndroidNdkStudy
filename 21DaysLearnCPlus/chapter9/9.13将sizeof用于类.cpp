// 将 sizeof 用于类及其实例的结果

#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
    private:
        char* buffer;

    public:
        MyString(const char* initString){
            buffer = NULL;
            if (initString!=NULL)
            {
                buffer = new char[strlen(initString)+1];
                strcpy(buffer,initString);
            }
        }

        MyString(const MyString& copySource){
            buffer = NULL;
            if (copySource.buffer != NULL)
            {
                buffer = new char[strlen(copySource.buffer)+1];
                strcpy(buffer,copySource.buffer);
            } 
        }
        
        ~MyString()
        {
            delete [] buffer;
        }

        int GetLength(){
            return strlen(buffer);
        }

        const char* GetString(){
            return buffer;
        }
};

class Human
{
    private:
        int age;
        bool gender;
        MyString name;

    public:
        Human(const MyString& InputName,int InputAge, bool gender):name(InputName),age(InputAge),gender(gender){}

        int GetAge(){
            return age;
        }    
};

int main(){
    MyString mansName("Adam");
    MyString womansName("Eve");


    //char* --> 8字节(64bit系统)
    cout << "sizeof(MyString) = "<<sizeof(MyString) <<endl;
    cout << "sizeof(mansName) = "<<sizeof(mansName) <<endl;
    cout << "sizeof(womansName) = "<<sizeof(womansName) <<endl;

    Human firstMan(mansName,25,true);
    Human firstWoman(womansName,18,false);

    //int --> 4,bool --> 1 ,Human --> 16(sizeof(xx)的结果受字填充（word padding）)
    cout << "sizeof(int) = "<<sizeof(int) <<endl;
    cout << "sizeof(bool) = "<<sizeof(bool) <<endl;
    cout << "sizeof(Human) = "<<sizeof(Human) <<endl;
    cout << "sizeof(firstMan) = "<<sizeof(firstMan) <<endl;
    cout << "sizeof(firstWoman) = "<<sizeof(firstWoman) <<endl;

    return 0;
}
