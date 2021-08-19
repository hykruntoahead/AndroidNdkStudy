#include <iostream>

using namespace std;
class Vehicle 
{ 
public: 
 Vehicle() {
    cout << "Vehicle" << endl;
 } 
 ~Vehicle(){
    cout << "~Vehicle" << endl;
 } 
}; 
class Car: public Vehicle 
{ 
public: 
 Car() {
     cout << "Car" << endl;
 } 
 ~Car() {
     cout << "~Car" << endl;
 } 
}; 

int main(){
    Vehicle* pMyRacer = new Car; 
    delete pMyRacer; 
}