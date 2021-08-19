//单例类

// 将关键字 static 用于类的数据成员时，该数据成员将在所有实例之间共享。
// 将 static 用于函数中声明的局部变量时，该变量的值将在两次调用之间保持不变。
// 将 static 用于成员函数（方法）时，该方法将在所有成员之间共享。

//单例类 President，它禁止复制、赋值以及创建多个实例
#include <iostream>
#include <string>

using namespace std;

class President
{
    private:
      President() {}; //私有构造函数
      President(const President&); //私有复制构造函数
      const President& operator = (const President&);//赋值运算符

      string name;

    public:
        static President& GetInstance(){
            static President onlyInstace;
            return onlyInstace;
        }
    
    string GetName(){
        return name;
    }

    void SetName(string InputName){
        name = InputName;
    }
};

int main()
{
    President& onlyPresident = President::GetInstance();
    onlyPresident.SetName("Abraham Lincoln");

    // uncomment lines to see how compile failures prohibit duplicates 
    // President second; // cannot access constructor 
    // President* third= new President(); // cannot access constructor 
    // President fourth = onlyPresident; // cannot access copy constructor 
    // onlyPresident = President::GetInstance(); // cannot access operator= 

    cout << "The name of the President is :";
    cout << President::GetInstance().GetName() << endl;

    return 0;
}