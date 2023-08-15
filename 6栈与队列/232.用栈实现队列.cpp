/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>
#include <list>
using namespace std;
// @lc code=start

//你所使用的语言也许不支持栈。你可以
//使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

class MyQueue {
public:
    //构造函数
    MyQueue() {

    }
    stack<int> stIn; //输入栈
    stack<int> stOut;  //输出栈
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty()){
           while(!stIn.empty()){
                int tmp=stIn.top();
                stIn.pop();
                stOut.push(tmp);
           }
        }
        int res=stOut.top();
        stOut.pop();
        return res;
    }
    
    //返回队列开头的元素
    int peek() {
        int res=this->pop();
        stOut.push(res);
        return res;
    }
    
    bool empty() {
        return stIn.empty()&&stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

