//实例化STL map和multimap(key:int,value:string)

#include<map>
#include<string>
using namespace std;

template <typename keyType>
struct ReverseSort{
    bool operator()(const keyType& key1,const keyType& key2){
        return (key1>key2);
    }
}

int main(){
    map<int,string> mapIntToStr1;
    multimap<int,string> mmapIntToStr1;

    map<int,string> mapTntToStr2(mapIntToStr1);
    multimap<int,string> mmapIntToStr2(mmapIntToStr1);

    map<int,string> mapIntToStr3(mapIntToStr1.cbegin(),mapIntToStr1.cend());
    multimap<int,string> mapIntToStr3(mmapIntToStr1.cbegin(),mmapIntToStr1.cend());
    
    map<int,string,ReverseSort<int>> mapIntToStr4(mapIntToStr1.cbegin(),
    (mapIntToStr1.cend());
    multimap<int,string,ReverseSort<int>> mapIntToStr4(mmapIntToStr1.cbegin(),
    (mmapIntToStr1.cend());

    return 0;

}