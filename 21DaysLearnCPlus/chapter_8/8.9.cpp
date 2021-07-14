// 使用偏移量和运算符来递增++和递减--指针

#include <iostream>
using namespace std;

int main(){
    cout << "How many integers you aish to enter?";

    int numEntires = 0;

    cin >> numEntires;

    int* pointsToInts = new int[numEntires];

    cout << "Allocated for " << numEntires << " integers " <<endl;
    
    for (int counter = 0; counter < numEntires; counter++)
    {
        /* code */
        cout << "Enter number " << counter << ":";
        cin >> *(pointsToInts + counter);
    }
    
    cout << "Diaplaying all numbers entered:" << endl;
    for (int counter = 0; counter < numEntires; counter++)
    {
        cout << *(pointsToInts++) << " ";
    }

    pointsToInts -= numEntires;

    delete[] pointsToInts;

    cout << endl;


    

}