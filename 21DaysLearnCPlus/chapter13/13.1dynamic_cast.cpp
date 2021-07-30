// 使用动态转换判断Fish指针指向是否是Tuna对象或Carp对象.
// 务必检查 dynamic_cast 的返回值，看它是否有效。如果返回值为 NULL，说明转换失败。

#include <iostream>
using namespace std;

class Fish
{
    public:
        virtual void Swim(){
            cout << "Fish swims in water" << endl;
        }

        virtual ~Fish(){}
};

//金枪鱼
class Tuna : public Fish{
    public: 
        void Swim(){
            cout << "Tuna swims real fast in the sea" << endl;
        }

        void BecomeDinner(){
            cout << "Tuna became dinnder in sushi" << endl;
        }
};

//鲤鱼
class Carp : public Fish{
    public:
        void Swim(){
            cout << "Carp swims real slow in the lake" << endl;
        }

        void Talk(){
            cout << "Carp talked Carp!" << endl;
        }
};

void DetectFishType(Fish * objFish){
    Tuna* objTuna = dynamic_cast<Tuna*>(objFish);
    if (objTuna) //检测类型转换是否成功
    {
       cout << "Detected Tuna.Making Tuna dinner:" << endl;
       objTuna->BecomeDinner();
    }

    Carp* objCarp = dynamic_cast<Carp*>(objFish);
    if (objCarp)
    {
        cout << "Detected Carp. Making carp talk:" << endl;
        objCarp->Talk();
    }
    cout << "Verifying type using virrual Fish:: Swim:" << endl;
    objFish->Swim();
    
}

int main(){
    Carp myLunch;
    Tuna myDinner;

    DetectFishType(&myDinner);
    cout << endl;
    DetectFishType(&myLunch);

    return 0;
}