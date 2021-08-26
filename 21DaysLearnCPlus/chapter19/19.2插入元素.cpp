//在STL set或multiset 中插入元素

/*
 * cbegin返回一个const_iterator，指向容器的第一个元素
 * const_iterator是一个指向const内容的迭代器。你可以对这个迭代器进行加减操作，和一般的迭代器一样。但是你不能通过这个迭代器来修改其所指向的内容。
 * begin返回的是一个一般迭代器，可以通过该迭代器进行读写操作。cbegin显然不能进行写操作，只可以读。
 * */
#include <set>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& container){
    for (auto element = container.cbegin();
         element != container.cend();
        ++element){
       cout << *element << ' ';
    }
    cout << endl;
}

int main(){
    set<int> setInts{202,151,-999,-1};
    setInts.insert(-1);

    cout << "Contents of the set: " << endl;
    DisplayContents(setInts);

    multiset <int> msetInts;
    msetInts.insert(setInts.begin(),setInts.end());
    msetInts.insert(-1);

    cout << "Contents of the multiset: " << endl;
    DisplayContents(msetInts);

    cout << "Number of instance of '-1' in the multiset are: ";
    // multiset::count(),返回multiset中有多少个元素存储了指定的值
    cout << msetInts.count(-1) << endl;
    return 0;
}