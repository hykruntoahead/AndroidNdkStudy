// 使用 std::unordered_set 及其方法 insert()、
// find()、size()、max_bucket_count()、load_factor()
// 和 max_load_factor() 

#include <unordered_set>
#include <iostream>
using namespace std;

template <typename T>

void DisplayContents(const T& cont){
    cout << "Unordered set contains: ";
    for(auto element = cont.cbegin();
            element != cont.cend();
            ++element){
                cout << *element << ' ';
            }
    cout << endl;
    cout << "Number of elements, size() = " << cont.size() << endl; 
    cout << "Bucket count = " << cont.bucket_count() << endl; 
    cout << "Max load factor = " << cont.max_load_factor() << endl; 
    cout << "Load factor: " << cont.load_factor() << endl << endl; 
}

int main(){
    unordered_set<int> usetInt{1,-3,2017,300,-1,989,-300,9,13,43};
    DisplayContents(usetInt);
    usetInt.insert(999);
    DisplayContents(usetInt);

    cout << "Enter int you want to check for existence in set: ";
    int input =0;
    cin >> input;
    auto elementFound = usetInt.find(input);

    if (elementFound != usetInt.end()){
        cout << *elementFound << " found in set " << endl;
    }else{
        cout << input << "not available in set " << endl;
    }

    return 0;
}