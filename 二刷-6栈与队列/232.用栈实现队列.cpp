/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1; //输入栈
    stack<int> s2; //输出栈
    
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        s2.push(res);
        return res;
    }
    
    bool empty() {
        return s2.empty() && s1.empty();
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

