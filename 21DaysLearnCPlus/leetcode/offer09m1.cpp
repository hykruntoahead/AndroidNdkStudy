//剑指Offer 09.用两个栈实现队列 第１种方式
//https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/5d3i87/
#include <stack>
#include <iostream> 
using namespace std;

class CQueue {
private:
 stack<int> inputStack  = 0;
 stack<int> outputStack = 0;

public:
    CQueue() {

    }
    
    void appendTail(int value) {
       
         //output　清空 ->倒转－＞input　
        while (!outputStack.empty()){
           inputStack.push(outputStack.top());
           outputStack.pop();
        }
        inputStack.push(value); 
    }
    
    int deleteHead() {

        // input　清空 ->倒转－＞output　
        while (!inputStack.empty()){
            outputStack.push(inputStack.top());
            inputStack.pop();
        }　

        if (outputStack.empty()){
            return -1;
        }
        
        int head = outputStack.top();
        outputStack.pop();
         
        return head;
    }
};

int main(int argc, char const *argv[])
{ 
    CQueue cQ;
  
    return 0;
}
