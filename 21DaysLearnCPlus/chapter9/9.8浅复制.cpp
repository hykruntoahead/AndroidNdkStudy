//浅拷贝实际上是对类成员的引用，
//深拷贝是对类成员的复制并且重新分配了内存。


//按值传递类（如 MyString）的对象带来的问题
#include <iostream>
#include <string.h>
using namespace std;

class MyString{
    private:
        char* buffer;

    public:
        MyString(const char* initString){
            buffer = NULL;
            if (initString != NULL)
            {
                buffer = new char[strlen(initString) + 1];
                strcpy(buffer,initString);
            }
        }

        ~MyString(){
            //会打印两次　crash 重复调用 delete 导致了程序崩溃
            cout << "Invoking destructor,clearing up" << endl;
            delete[] buffer;
        }

        int GetLength(){
            return strlen(buffer);
        }    

        const char* GetString(){
            return buffer;
        }
};

void UseMyString(MyString str){
    cout <<"String buffer in MyString is "<< str.GetLength();
    cout << "characters long " << endl;

    cout << "buffer contains: " << str.GetString() << endl;
    return;
}

int main(){
    MyString sayHello("Hello from String Class");
    UseMyString(sayHello);

    return 0;
}