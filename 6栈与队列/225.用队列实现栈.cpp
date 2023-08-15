/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>
using namespace std;
// @lc code=start

//队列先进先出
//用两个队列实现一个后入先出的栈
//也可以只使用一个队列就可以实现栈的功能

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;//辅助队列 用来备份 也可用单个队列实现

    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        //将q1中元素导入到q2中，只保留最后一个元素，即为pop元素，再将q2清空
        int size=q1.size()-1;
        while(size){
            q2.push(q1.front());
            q1.pop();
            size--;
        }
        int res=q1.front();
        q1.pop();
        q1=q2;
        while(!q2.empty()){
            q2.pop();
        }
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

