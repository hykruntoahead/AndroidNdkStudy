// 定义一个复制构造函数，确保对动态分配的缓冲区进行深复制

// 注:通过在复制构造函数声明中使用 const，可确保复制构造函数不会修改指向的源对象。另
// 外，复制构造函数的参数必须按引用传递，否则复制构造函数将不断调用自己，直到耗
// 尽系统的内存为止

#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
    private:
        char* buffer;

    public:
        MyString(const char* initString)
        {
            buffer = NULL;
            cout << "Default constructor:creating new MyString" << endl;

            if (initString != NULL)
            {
                buffer = new char[strlen(initString) + 1];
                strcpy(buffer,initString);

                cout << "buffer points to : " << hex;
                cout << (unsigned int*)buffer << endl;
            }    
        }

        MyString(const MyString& copySource){ // copy constructor
            buffer = NULL;
            cout << "Copy constructor:copying from MyString" << endl;
            if (copySource.buffer != NULL)
            {
                buffer = new char[strlen(copySource.buffer) +1];

                strcpy(buffer,copySource.buffer);
                cout << "buffer points to : " << hex;
                cout << (unsigned int *)buffer << endl;
            }
            
        }

        ~MyString(){
            cout << "Invoking destructor,clearing up "<< hex;
            cout <<  (unsigned int *)buffer << endl;
            delete [] buffer;
        }

        int GetLength(){
            return strlen(buffer);
        }

        const char* GetString(){
            return buffer;
        }    
};

void UseMyString(MyString str){
    cout << "String buffer in MyString is " << str.GetLength();
    cout << " characters long" << endl;

    cout << "buffer contains: " << str.GetString() << endl;
    return;
}

int main(){
    MyString sayHello("Hello from String Class");
    UseMyString(sayHello);

    return 0;
}