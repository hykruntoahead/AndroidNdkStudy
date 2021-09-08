//剑指Offer 09.用两个栈实现队列　第二种方式（对m1的优化）
//https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/5d3i87/
#include <stack>
#include <iostream> 
using namespace std;

class CQueue {
private:
 stack<int> sA,sB;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
        sA.push(value); 
    }
    
    int deleteHead() { 
        
        if (sB.empty() && sA.empty()){
            return -1;
        }
        
        if(sB.empty()){
            while (!sA.empty()){
                sB.push(sA.top());
                sA.pop();
            } 
        }
      
        if (!sB.empty()){
            int head = sB.top();
            sB.pop()
            return head;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{ 
    CQueue cQ;
  
    return 0;
}
