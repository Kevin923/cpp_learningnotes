/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
using namespace std;

//单栈法实现
class MinStack {
public:
    
    stack<int> st;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    //如果加入的元素 小于当前最小值 则把当前最小值 和加入的值同时入栈
    void push(int val) {
        if(val <= min) {
            st.push(min);
            min = val;
        }
        st.push(val);
    }
    
    void pop() {
        //栈顶元素是最小值，把最小值赋值给她下面的元素 然后他俩出栈
        if(st.top() == min) {
            st.pop();
            min = st.top();
            st.pop();
        } 
        //不是最小值直接出栈
        else {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

