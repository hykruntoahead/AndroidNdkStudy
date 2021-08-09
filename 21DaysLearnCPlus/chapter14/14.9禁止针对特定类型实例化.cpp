// static_assert 是 C++11 新增的一项功能，
// 让您能够在不满足指定条件时禁止编译。

 template <typename T> class EverythingButInt { 
  public: 
    EverythingButInt() 
    { 
     static_assert(sizeof(T) != sizeof(int), "No int please!"); 
    } 
   };  
    int main() 
    { 
    EverythingButInt<int> test; // template instantiation with int. 
    return 0; 
} 