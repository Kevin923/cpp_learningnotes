/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;
        int res = 0;
        st.push(0); //栈中原元素为数组下标 
        //栈顶到栈底元素 从大到小
        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] > heights[st.top()]) {
                st.push(i);
            }
            else if(heights[i] == heights[st.top()]) {
                st.pop(); // 可以删除，效果一样，思路不同
                st.push(i);
            }
            else {
                while(!st.empty() && heights[st.top()] > heights[i]) {
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()) {
                        int w = i - st.top() - 1;
                        int h = 
                    }
                }
            }
        }
    }
};
// @lc code=end

