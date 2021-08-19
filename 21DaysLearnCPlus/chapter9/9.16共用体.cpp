//在结构中，常使用共用体来模拟复杂的数据类型。共用体可将固定的内存空间解释为另一种类型，
// 有些实现利用这一点进行类型转换或重新解释内存，但这种做法存在争议，而且可采用其他替代方式

#include <iostream>
using namespace std;


//为对于共用体，编译器为其预留最大成员占用的内存量
union SimpleUnion
{
    int num;
    char alphabet;

};

//这个结构使用枚举来存储信息类型，并使用共用体来存储实际值。这是共用体的一种常见用法
struct ComplexType
{
    enum DataType{
        Int,
        Char,
    }Type;

    union Value{
        int num;
        char alphabet;

        // 由于共用体包含的是普通数据类型，因此这些构造函数和析构函数是可选的，
        // 但如果共用体包含用户定义的数据类型（如类或结构），构造函数和析构函数就可能是必不可少的
        
        Value(){}
        ~Value(){}
    }value;
};

void DisplayComplexType(const ComplexType& obj){
    switch(obj.Type)
    {
        case ComplexType::Int:
            cout << "Union contains number: " << obj.value.num << endl;
            break;

        case ComplexType::Char:
            cout << "Union contains character: " << obj.value.alphabet << endl;
            break;   
    }
}

int main(){
    SimpleUnion u1,u2;
    u1.num = 2100;
    u2.alphabet = 'C';

    cout << "sizeof(u1) containing integer: " << sizeof(u1) << endl;
    cout << "sizeof(u2) containing integer: " << sizeof(u2) << endl;

    ComplexType myData1,myData2;
    myData1.Type = ComplexType::Int;
    myData1.value.num = 2017;

    myData2.Type = ComplexType::Char;
    myData2.value.alphabet = 'X';

    DisplayComplexType(myData1);
    DisplayComplexType(myData2);

    return 0;
}
