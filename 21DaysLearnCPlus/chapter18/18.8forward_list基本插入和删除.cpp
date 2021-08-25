#include<forward_list> 
#include<iostream> 
using namespace std; 


//，forward_list 与 list 很像。鉴于 forward_list 不支持双向迭代，因此只能对迭代器使用运
// 算符++，而不能使用--。

template <typename T> 
void DisplayContents (const T& container) 
{ 
 for (auto element = container.cbegin(); 
 element != container.cend (); 
 ++ element) 
 cout << *element << ' '; 
 
 cout << endl; 
 } 
 
 int main() { 
 forward_list<int> flistIntegers{ 3, 4, 2, 2, 0 }; 
 flistIntegers.push_front(1); 

 cout << "Contents of forward_list: " << endl; 
 DisplayContents(flistIntegers); 

 
 flistIntegers.remove(2); 
 flistIntegers.sort(); 
 cout << "Contents after removing 2 and sorting: " << endl; 
 DisplayContents(flistIntegers); 

 return 0; 
} 