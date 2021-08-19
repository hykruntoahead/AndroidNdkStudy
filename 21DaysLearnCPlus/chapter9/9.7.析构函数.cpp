//每当对象不再在作用域内或通过 delete 被删除进而被销毁时，都将调用析构函数。这使得析构函
// 数成为重置变量以及释放动态分配的内存和其他资源的理想场所。

// 封装字符缓冲区并通过析构函数释放它

#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
    private:
        char* buffer;

    public:
        MyString(const char* initString){
            if (initString != NULL)
            {
                 buffer = new char[strlen(initString) +1];
                 //用标准库函数 strcpy 将 输入字符串 initString 复制到 buffer 指向的新分配的内存中
                 strcpy(buffer,initString);
            }else{
                buffer = NULL;
            }
            
        }
        ~MyString(){
            cout << "Invokong destructor,clearing up" << endl;
            if (buffer != NULL)
            {
                 delete [] buffer;
            }
            
        } 

        int GetLength(){
            return strlen(buffer);
        }

        const char* GetString(){
            return buffer;
        }   
};

int main(){
    MyString sayHello("Hello from String Class");
    cout << "String buffer in sayHello is " << sayHello.GetLength();
    cout << " characters long" << endl;

    cout << "Buffer contains: "<<sayHello.GetString() << endl; 
}