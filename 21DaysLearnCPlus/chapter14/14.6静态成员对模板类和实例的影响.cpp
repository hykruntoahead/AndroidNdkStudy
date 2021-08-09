// 输出表明，编译器在两个不同的静态成员中存储了两个不同的值，
// 但这两个静态成员都名为 staticVal。也就是说，对于针对每种类型
// 具体化的类，编译器确保其静态变量不受其他类的影响

#include <iostream>
using namespace std;

template <typename T>

class TestStatic{
    public:
        static int staticVal;
};

//不可或缺，它初始化模板类的静态成员：
template<typename T> int TestStatic<T> :: staticVal;

int main(){
    TestStatic<int> intInstance;
    cout << "Settings staticVal for intInstance to 2011" << endl;
    intInstance.staticVal = 2011;

    TestStatic<double> dbInstance;
    cout << "Settings staticVal for Double)2 to 1011" << endl;
    dbInstance.staticVal = 1011;

    cout << "intInstance.staticVal = " << intInstance.staticVal << endl;
    cout << "dbInstance.staticVal = " << dbInstance.staticVal << endl;

    return 0;
}