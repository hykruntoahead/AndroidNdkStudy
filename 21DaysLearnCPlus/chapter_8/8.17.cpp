// 引用是相应变量的别名
// 引用让您能够访问相应变量所在的内存单元，这使得编写函数时引用很有用。

#include <iostream>
using namespace std;

int main(){
    int original = 30;

    cout << "original = " << original << endl;
    cout << "original is at address: " << &original << endl;

    int& ref1 = original;
    cout << "Ref1 is at address: " << &ref1 << endl;
    cout << "Therefore, ref1 = " << dec << ref1 << endl;

    int& ref2 = ref1;
    cout << "ref2 is at address: " << &ref2 << endl;
    cout << "Therefore, ref2 = " << dec << ref2 << endl;
    
    return 0;
}