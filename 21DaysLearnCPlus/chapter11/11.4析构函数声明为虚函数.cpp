// 将析构函数声明为虚函数，确保通过基类指针调用 delete 时，将调用派生类的析构函数

#include <iostream>
using namespace std;

class Fish{
    public:
    Fish(){
        cout << "Constructed Fish" <<endl;
    }

    virtual ~Fish(){
        cout << "Destroyed Fish" << endl;
    } 
};

class Tuna:public Fish{
    public:
        Tuna(){
            cout << "Constructed Tuna" <<endl;
        }

        ~Tuna(){
            cout << "Destroyed Tuna" << endl;
        }
};

void DeleteFishMemory(Fish* pFish){
    delete pFish;
}

int main(){
    cout << "Allocating a tuna on the free store:" << endl;
    Tuna* pTuna = new Tuna;
    cout << "Deleting the Tuna: " << endl;
    DeleteFishMemory(pTuna);


    cout << "Instantiating a Tuna on the stack:" << endl; 
    Tuna myDinner; 
    cout << "Automatic destruction as it goes out of scope: " << endl; 
    return 0;
}