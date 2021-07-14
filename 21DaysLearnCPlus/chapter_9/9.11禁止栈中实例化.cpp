//　数据库类 MonsterDB，只能使用 new 在自由存储区中创建其对象

#include <iostream>
using namespace std;

class MonsterDB
{
    private:
        ~MonsterDB(){};

    public:
        static void DestroyInstance(MonsterDB* pInstance){
            delete pInstance;
        }

        void DoSomething(){
            cout << "do something" << endl;
        }    
};

int main(){
    MonsterDB* myDB = new MonsterDB();
    myDB->DoSomething();

    // delete myDB;//由於析构函数为private　所以无法访问　无法正常delete

    MonsterDB::DestroyInstance(myDB);

    return 0;
}

