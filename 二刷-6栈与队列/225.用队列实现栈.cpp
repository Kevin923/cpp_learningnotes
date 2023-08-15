/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {

    }
    queue<int> q1;
    queue<int> q2;////辅助队列 用来备份 也可用单个队列实现
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size() - 1;
        while(size){
            q1.push(q1.front());
            q1.pop();
            size--;
        }
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

